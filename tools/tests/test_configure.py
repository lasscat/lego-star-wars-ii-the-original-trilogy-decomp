"""Asset-free regression tests for per-source mwcc language selection.

Extract the real flag expression, command expression and edge-generation functions
without running configure.py's command-line handling, downloads or ROM extraction.
These tests do not establish matching code generation; full-ROM verify still does.
"""

import ast
import os
import shlex
import tempfile
import types
import unittest
from pathlib import Path
from typing import Generator


CONFIGURE = Path(__file__).resolve().parents[1] / "configure.py"


def load_build_parts(game_config=None):
    tree = ast.parse(CONFIGURE.read_text(encoding="utf-8"))
    functions = {"is_c", "is_cpp", "get_c_cpp_files", "add_mwcc_builds"}
    nodes = [
        node for node in tree.body
        if isinstance(node, ast.FunctionDef) and node.name in functions
        or isinstance(node, ast.Assign)
        and any(isinstance(target, ast.Name) and target.id == "CC_FLAGS" for target in node.targets)
    ]
    command = next(
        node for node in ast.walk(tree)
        if isinstance(node, ast.Assign)
        and any(isinstance(target, ast.Name) and target.id == "mwcc_cmd" for target in node.targets)
    )
    namespace = {
        "GAME_CFG": game_config or {},
        "Path": Path,
        "os": os,
        "Generator": Generator,
        "Project": object,
        "ninja_syntax": types.SimpleNamespace(Writer=object),
        "compiler_overrides": lambda project: {},
        "src_path": Path("src"),
        "libs_path": Path("libs"),
        "mwcc_root": Path("tools/mwccarm"),
        "CC": "tools/mwccarm/2.0/sp1p5/mwccarm.exe",
        "WINE": "wibo",
        "SJISWRAP": "sjiswrap.exe",
        "CC_INCLUDES": "-i include",
    }
    exec(compile(ast.Module(body=nodes + [command], type_ignores=[]), str(CONFIGURE), "exec"), namespace)
    return namespace


class Edges:
    def __init__(self):
        self.edges = []

    def build(self, **edge):
        self.edges.append(edge)

    def newline(self):
        pass


class CompilerLanguageTests(unittest.TestCase):
    def edges(self, namespace):
        namespace["get_c_cpp_files"] = lambda directories: iter([
            Path("src/auto/natural_c.c"), Path("src/auto/natural_cpp.cpp"),
        ])
        project = types.SimpleNamespace(game_build=Path("build/usa"), game_version="usa")
        writer = Edges()
        namespace["add_mwcc_builds"](writer, project, [])
        return [edge for edge in writer.edges if edge["rule"] == "mwcc"]

    def test_default_non_language_flags_are_unchanged(self):
        self.assertEqual(
            load_build_parts()["CC_FLAGS"],
            "-O4,p -enum int -char signed -str noreuse -proc arm946e "
            "-gccext,on -fp soft -inline noauto -Cpp_exceptions off -RTTI off "
            "-interworking -w off -sym on -gccinc -nolink -msgstyle gcc",
        )

    def test_legacy_game_language_does_not_add_global_selector(self):
        for language in ("c", "c++"):
            with self.subTest(language=language):
                flags = shlex.split(load_build_parts({"lang": language})["CC_FLAGS"])
                self.assertFalse(any(flag.startswith("-lang") for flag in flags))

    def test_generated_commands_have_one_correct_selector(self):
        namespace = load_build_parts({"lang": "c"})
        for edge, expected in zip(self.edges(namespace), ("-lang=c", "-lang=c++")):
            with self.subTest(source=edge["inputs"]):
                variables = edge["variables"]
                command = namespace["mwcc_cmd"].replace("$cc_flags", variables["cc_flags"])
                command = command.replace("$cc_extra", variables["cc_extra"])
                selectors = [flag for flag in shlex.split(command) if flag.startswith("-lang")]
                self.assertEqual(selectors, [expected])

    def test_per_file_profile_keeps_extension_language(self):
        namespace = load_build_parts()
        namespace["compiler_overrides"] = lambda project: {
            "src/auto/natural_cpp.cpp": ("1.2/sp2p3", "-O2 -proc arm7tdmi"),
        }
        edge = self.edges(namespace)[1]
        self.assertEqual(edge["variables"]["cc_flags"], "-lang=c++")
        self.assertEqual(edge["variables"]["cc_extra"], "-O2 -proc arm7tdmi")
        self.assertEqual(edge["variables"]["cc"], "./tools/mwccarm/1.2/sp2p3/mwccarm.exe")

    def test_source_discovery_includes_c_and_cpp_only(self):
        namespace = load_build_parts()
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            for name in ("natural.c", "natural.cpp", "header.h", "assembly.s"):
                (root / name).touch()
            found = {path.name for path in namespace["get_c_cpp_files"]([root])}
            self.assertEqual(found, {"natural.c", "natural.cpp"})


if __name__ == "__main__":
    unittest.main()
