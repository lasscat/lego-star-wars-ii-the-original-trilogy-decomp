"""Tests for separating mechanical and C-only progress measures."""

import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import match


class CSourceMeasuresTests(unittest.TestCase):
    def test_assembly_bearing_units_are_excluded_conservatively(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / "src").mkdir()
            (root / "src/natural.c").write_text("int f(void) { return 1; }\n")
            (root / "src/legacy.c").write_text('asm void f(void) { "nop"; }\n')
            report = {
                "units": [
                    {
                        "metadata": {"source_path": "src/natural.c"},
                        "measures": {"matched_code": 40, "matched_functions": 2},
                    },
                    {
                        "metadata": {"source_path": "src/legacy.c"},
                        "measures": {"matched_code": 60, "matched_functions": 3},
                    },
                    {
                        "metadata": {"source_path": "src/generated.c", "auto_generated": True},
                        "measures": {"matched_code": 100, "matched_functions": 5},
                    },
                ]
            }

            self.assertEqual(match.c_source_measures(report, root), (40, 2))

    def test_missing_source_is_excluded(self):
        report = {
            "units": [
                {
                    "metadata": {"source_path": "src/missing.c"},
                    "measures": {"matched_code": 40, "matched_functions": 2},
                }
            ]
        }
        with tempfile.TemporaryDirectory() as temporary:
            self.assertEqual(match.c_source_measures(report, Path(temporary)), (0, 0))


if __name__ == "__main__":
    unittest.main()
