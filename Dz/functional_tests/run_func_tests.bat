@echo off
cd ..
for %%n in (0, 1, 2, 3, 4, 5, 6) do (
	main.exe functional_tests\in_%%n.txt
)