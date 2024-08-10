# Environment
OS=$(uname -s)
if [[ "$OS" == "MINGW"* || "$OS" == "CYGWIN"* ]]; then
    # It's a Windows-like environment (e.g., Git Bash or Cygwin)
    EXT=".exe"
else
    # It's a Unix-like environment (Linux, macOS, etc.)
    EXT=""
fi
COMPILER=`which tcc`
FLAGS='-Wall -g'

# Project
PROJECT_NAME=$(basename "$(pwd)")
SRC_DIR='./src'
OUT_DIR='./out'
BIN_FILE="$OUT_DIR/$PROJECT_NAME$EXT"

check_status() {
  if [ $? -ne 0 ]; then
    echo "Error: $1 failed!"
    exit 1
  fi
}

echo -e "Compiler: $COMPILER\n"
echo "Compiling core..."
$COMPILER $FLAGS -c "$SRC_DIR/core/rt.c" -o "$OUT_DIR/core_rt.o"
check_status "Core compilation"

echo "Compiling main..."
$COMPILER $FLAGS -c "$SRC_DIR/main.c" -o "$OUT_DIR/main.o"
check_status "Main compilation"

echo "Assembling binary..."
$COMPILER $FLAGS -o $BIN_FILE "$OUT_DIR/core_rt.o" "$OUT_DIR/main.o"
check_status "Assembling"

echo -e "\nProgram executable ready at: $BIN_FILE"
