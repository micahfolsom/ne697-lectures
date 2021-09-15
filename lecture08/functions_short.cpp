// Pass-by-value
void by_value(int x) {
  // x is a copy, so while its value changes locally, the input variable is
  // not modified
  x += 1000;
  return;
}

// Pass-by-reference
void by_ref(int& x) {
  // We got the address of the data, so the input variable is modified (not
  // copied) - lasting consequences
  x += 1000;
  return;
}

// Pass-by-const-reference
void by_const_ref(int const& x) {
  // We can't even compile this - the const guarantees we can't change the
  // value, and we avoid the copy
  //x += 1000;
  return;
}

// Pass-by-pointer
void by_pointer(int* x) {
  // We got the address of the data, so the input variable is modified (not
  // copied) - lasting consequences
  (*x) += 1000;
  return;
}
