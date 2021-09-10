#include <iostream>
using namespace std;

// There are 4 main patterns of function input arguments you'll see. Sometimes
// you'll see a mix, depending on what needs to be done to each input argument.
// int is just a stand-in, and can be any type or object - the semantics are
// the same
// There are occasionally reasons to do other things, like passing a constant
// pointer, but these 4 cases are by far the most common

// Pass-by-value
// Just passes the value, so it *copies* the input to the local variable x
void by_value(int x) {
  // No effect! x is a local variable
  x += 1000;
  return;
}
// We could do this, but then when we call the function, we have to do
// var = by_value(var);
// which isn't ideal
/*int by_value(int x) {
  x += 1000;
  return x;
}*/

// Pass-by-reference
// Passes the *address* of the variable, so we avoid the copy, and can modify
// it
void by_ref(int& x) {
  // x changes the input variable
  x += 1000;
  return;
}

// Pass-by-const-reference
// Passes "a reference to a constant int". We avoid the copy by passing the
// address, *and* we enforce that the value of x cannot change
// This is what I use most often
void by_const_ref(int const& x) {
  // NOPE! Compiler won't allow this to even compile. We're guaranteeing that
  // x is constant
  //x += 1000;
  return;
}

// Pass-by-pointer
// Now we're passing an address, and capturing it in a local pointer to an int.
// We modify the input, just like with "int& x", since we got the address, but
// we'll need to dereference it
void by_pointer(int* x) {
  (*x) += 1000;
  // Either is ok. Use () liberally, as the ordering can quickly get confusing
  // with pointers
  //*x += 1000;
  return;
}

int main(int argc, char* argv[]) {
  int test = 5;
  by_value(test);
  cout << "test after by_value(): " << test << endl;
  by_ref(test);
  cout << "test after by_ref(): " << test << endl;
  by_const_ref(test);
  cout << "test after by_const_ref(): " << test << endl;
  // Note the &, because we're passing the *address*, to be captured by the
  // pointer
  by_pointer(&test);
  cout << "test after by_pointer(): " << test << endl;
  return 0;
}
