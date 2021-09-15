int main(int argc, char* argv[]) {
  // There are multiple ways to write constant values
  // One is more like English, which is tempting...
  const int SIZE1 = 10;
  // But this is more correct!
  int const SIZE2 = 100;

  // The reason is because of how const evaluates: it applies to its left,
  // and if there's nothing there, then to its right
  // Because of this, if you put const in "the correct place" (where you put
  // things to its left, first, the way its evaluated), then if you read
  // the type from right to left, you will always have the correct
  // interpretation
  /*
   int const -> "a constant int value"

   int const* -> "a pointer to a constant int value"

   BAD: const int* -> "???" behaves the same as above!

   int* const -> "a constant pointer to an int value"

   int const* const -> "a constant pointer to a constant int value"
  */
  return 0;
}
