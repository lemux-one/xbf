COMPILER=`which tcc`
SRC_DIR='./src'
OUT_DIR='./out'
BIN_NAME='xbf'

echo "Compiler: $COMPILER"
echo "Compiling core..."
$COMPILER -c "$SRC_DIR/core/rt.c" -o "$OUT_DIR/core_rt.o"

echo "Compiling main..."
$COMPILER -c "$SRC_DIR/main.c" -o "$OUT_DIR/main.o"

echo "Assembling binary..."
$COMPILER -o "$OUT_DIR/$BIN_NAME.exe" "$OUT_DIR/core_rt.o" "$OUT_DIR/main.o"

echo "Done!"
