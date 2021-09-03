#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
  // ++ and --: increment and decrement by 1
  int a = 0;
  a++; // a == 1
  // Note ++a vs a++: the prefix gets evaluated before the statement
  // The suffix gets evaluated after the statement
  int b = a++; // b == 1

  // Basic math
  int c = a + b;
  // "Compound" operator; math operator, then assignment operator
  a += 3;
  // Shorthand for this
  a = a + 3;

  // Bool: only true or false. Lower case!
  bool fa = false;
  bool fb = true;

  // 0 -> false
  // Anything non-0 -> true
  bool fc = 5;
  if (5) {
    std::cout << "This prints!" << std::endl;
  }
  if (fa && fb) {
    std::cout << "Does not print" << std::endl;
  }
  if (fa || fb) {
    std::cout << "Yep, this prints" << std::endl;
  }

  // You can add more than just numbers. The operators can be arbitrarily
  // defined in C++. It's just a function that looks something (not exactly)
  // like this:
  // std::string operator+(std::string right_hand_side);
  // It takes a string in (the right hand side of the +) and returns another
  // string that is the combination of the two
  std::string s = "My string with a newline\n";
  s += " more of a string. A number: ";
  // std::to_string() will helpfully convert any basic type into a string
  s += std::to_string(5.0);
  // Note the use of "escapes" (\) here, so the " is captured in the string
  std::cout << "The \"s\" string contains: " << s << std::endl;

  // Basic comparison
  if (a < 5) {
    std::cout << "a is less than 5" << std::endl;
  }

  // if-else
  if (bool d = (a > 5)) {
    // The variable "d" ONLY exists in this if() statement
    // It's in the if() statement's "scope", and only exists here
    std::cout << "d must be true: " << d << std::endl;
  } else if (b > 10) {
    std::cout << "b was greater than 10 AND a > 5" << std::endl;
  } else {
    std::cout << "a < 5 and b < 10" << std::endl;
  }
  // Cannot access "d" here (undeclared variable), not in our scope!

  // Be wary of single lines! Don't do this!
  if (a < 5)
    std::cout << "This executes if a < 5" << std::endl;
    // Punk'd by indentation. This is not in the if() statement!
    std::cout << "Not in the if statement! a could be anything!" << std::endl;
  if (a < 5) {
    std::cout << "This executes if a < 5" << std::endl;
    std::cout << "YES in the if statement! a < 5" << std::endl;
  }

  int n = 10;
  // i++ or ++i is personal preference, they are equivalent when i is alone
  // Note that, like "d" above, "i" is local to the loop
  for (int i = 0 ; i < n ; i++) {
    std::cout << "Loop iteration " << i << std::endl;
  }
  // Not a re-declaration. The above "i" no longer exists, because it was only
  // in the scope of the for() loop
  int i = 0;
  // Same as above, but a little clunkier
  while (i < 10) {
    // a bunch of stuff
    i++;
  }

  // See the arrays.cpp file for array/vector examples
  std::vector<int> some_numbers = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  // "Range-based" for loop; no index, just iterating over each element
  for (auto a_number : some_numbers) {
    std::cout << a_number << std::endl;
  }
  // Does the same thing but now we have the index
  // Also note a different letter. We have "int i = 0" above, so declaring it
  // here would be a re-declaration of an existing variable!
  for (std::size_t j=0;j < some_numbers.size();++j) {
    some_numbers[j] += 10;
  }

  // Use enums when you have a finite set of discrete options
  // These are just numbers underneath: Neutron==0, Gamma==1, Neutrino==2
  // It's a lot clearer with a label!
  enum ParticleType { Neutron, Gamma, Neutrino };
  ParticleType particle_type = Neutron;
  if (particle_type == Gamma) {
    std::cout << "Particle was a Gamma" << std::endl;
  } else if (particle_type == Neutron) {
    std::cout << "Particle was a Neutron" << std::endl;
  }

  // Think "look-up table". Just a map from an option to a code block
  // A bit clearer/easier than a big chain of if(), else if(), else if(), ...
  switch (particle_type) {
    case Gamma:
    // If you're declaring new variables inside the case, you *must* have the
    // curly braces. Otherwise, they're not required
    {
      int h = 10;
      std::cout << "switch(): it was a Gamma" << std::endl;
      std::cout << "h = " << h << " only exists in this case block" << std::endl;
      // multiple lines are ok, even without the { }
      break;
    }

    case Neutron:
      std::cout << "switch(): it was a Neutron" << std::endl;
      // ...
      // oops! we forgot break;
      // Now the "case Neutrino:" block executes too, ruh roh!

    case Neutrino:
      std::cout << "switch(): it was a Neutrino" << std::endl;
      break;

    // You always want to have a default/fall-through case so you know when
    // you messed up above
    default:
      // Remember, whitespace doesn't matter. The line ends when it hits the ;
      // So we can just continue on the next line like below
      std::cout << "No cases matched in the switch(). Did you forget to add a"
        << " case?" << std::endl;
      break;
  }
  // It's not just numbers. switch() works on any expression that evaluates to a
  // single value.
  char var = 'm';
  switch (var) {
    case 'a':
      std::cout << "var was 'a'" << std::endl;
      break;
    case 'm':
      std::cout << "var was 'm'" << std::endl;
      break;
  }
  return 0;
}
