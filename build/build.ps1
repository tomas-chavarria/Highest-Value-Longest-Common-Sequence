$SOURCE = "../src/longest-common-subsequence.cpp"
$OUTPUT = "../bin/hvlcs.exe"

Write-Host "Compiling $SOURCE..."
g++ -std=c++17 -Wall -Wextra -O2 $SOURCE -o $OUTPUT

if ($LASTEXITCODE -eq 0) {
    Write-Host "Compilation successful."
} else {
    Write-Host "Compilation failed."
}