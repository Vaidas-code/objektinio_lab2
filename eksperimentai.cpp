#include "eksperimentai.h"

int main()
{
    // Size
    std::cout << "SIZE:" << endl;
    Vektorius<int> nums {1, 3, 5, 7};
 
    std::cout << "nums contains " << nums.size() << " elements.\n";

    // Max_size
    std::cout << "MAX_SIZE:" << endl;
    Vektorius<char> q;
    std::cout.imbue(std::locale("en_US.UTF-8"));    
    std::cout << "Maximum size of a Vektorius is " << q.max_size() << '\n';

    // Capacity
    std::cout << "CAPACITY:" << endl;
    Vektorius<char> q1;
    std::cout.imbue(std::locale("en_US.UTF-8"));    
    std::cout << "Maximum size of a Vektorius is " << q1.max_size() << '\n';

    // Resize
    std::cout << "RESIZE:" << endl;
    Vektorius<int> c = {1, 2, 3};
    std::cout << "The vector holds: ";
    for (const auto& el: c)
        std::cout << el << ' ';
    std::cout << '\n';
 
    c.resize(5);
    std::cout << "After resize up to 5: ";
    for (const auto& el: c)
        std::cout << el << ' ';
    std::cout << '\n';
 
    c.resize(2);
    std::cout << "After resize down to 2: ";
    for (const auto& el: c)
        std::cout << el << ' ';
    std::cout << '\n';
 
    c.resize(6, 4);
    std::cout << "After resize up to 6 (initializer = 4): ";
    for (const auto& el: c)
        std::cout << el << ' ';
    std::cout << '\n';

    // empty
    std::cout << "EMPTY:" << endl;
    std::cout << std::boolalpha;
    Vektorius<int> numbers;
    std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';
 
    numbers.push_back(42);
    std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';

    //shrink_to_fit
    std::cout << "SHRINK_TO_FIT" << endl;
    Vektorius<int> v5;
    std::cout << "Default-constructed capacity is " << v5.capacity() << '\n';
    v5.resize(100);
    std::cout << "Capacity of a 100-element vector is " << v5.capacity() << '\n';
    v5.resize(50);
    std::cout << "Capacity after resize(50) is " << v5.capacity() << '\n';
    v5.shrink_to_fit();
    std::cout << "Capacity after shrink_to_fit() is " << v5.capacity() << '\n';
    v5.clear();
    std::cout << "Capacity after clear() is " << v5.capacity() << '\n';
    v5.shrink_to_fit();
    std::cout << "Capacity after shrink_to_fit() is " << v5.capacity() << '\n';
    for (int i = 1000; i < 1300; ++i)
        v5.push_back(i);
    std::cout << "Capacity after adding 300 elements is " << v5.capacity() << '\n';
    v5.shrink_to_fit();
    std::cout << "Capacity after shrink_to_fit() is " << v5.capacity() << '\n';
    //reserve
    std::cout << "RESERVE: " << endl;
    Vektorius<int> myVector;
    std::cout << "Initial capacity: " << myVector.capacity() << std::endl;
    myVector.reserve(10);
    std::cout << "After reserving capacity: " << myVector.capacity() << std::endl;
    for (int i = 1; i <= 10; i++) {
        myVector.push_back(i);
    }
    std::cout << "Size after inserting elements: " << myVector.size() << std::endl;
    // operator[]
    std::cout << "OPERATOR[]: " << endl;
    Vektorius<int> myArray(5);
    std::cout << "Elements of myArray:" << std::endl;
    for (size_t i = 0; i < 5; i++) {
        std::cout << "Element at index " << i << ": " << myArray[i] << std::endl;
    }
    myArray[2] = 10;
    std::cout << "Updated element at index 2: " << myArray[2] << std::endl;
    const Vektorius<int>& constArray = myArray;
    std::cout << "Constant element at index 3: " << constArray[3] << std::endl;

    // at
    std::cout << "AT: " << endl;
    Vektorius<int> myVector2(5);
  std::cout << "Elements of myVector:" << std::endl;
  for (size_t i = 0; i < myVector2.size(); i++) {
    std::cout << "Element at index " << i << ": " << myVector2.at(i) << std::endl;
  }
  myVector2.at(2) = 10;
  std::cout << "Updated element at index 2: " << myVector2.at(2) << std::endl;
  const Vektorius<int>& constVector = myVector2;
  std::cout << "Constant element at index 3: " << constVector.at(3) << std::endl;
  // front
  std::cout << "FRONT: " << endl;
  Vektorius<int> myVector3 = {4,5,6,7,8,9,10};
  std::cout << "The first element of myVector: " << myVector3.front() << std::endl;
  // back
  std::cout << "BACK: " << endl;
  std::cout << "The last element of myVector: " << myVector3.back() << std::endl;
  // begin()
  std::cout << "BEGIN(): " << endl;
  Vektorius<int> nums1 {1, 2, 4, 8, 16};
    Vektorius<std::string> fruits {"orange", "apple", "raspberry"};
    Vektorius<char> empty;
    std::for_each(nums1.begin(), nums1.end(), [](const int n) { std::cout << n << ' '; });
    std::cout << '\n';
    std::cout << "Sum of nums: "
              << std::accumulate(nums1.begin(), nums1.end(), 0) << '\n';
    if (!fruits.empty())
        std::cout << "First fruit: " << *fruits.begin() << '\n';
    if (empty.begin() == empty.end())
        std::cout << "vector 'empty' is indeed empty.\n";
    //end()
    std::cout << "END():" << endl;
    std::for_each(nums.begin(), nums.end(), [](const int n) { std::cout << n << ' '; });
    std::cout << '\n';
    std::cout << "Sum of nums: "
              << std::accumulate(nums.begin(), nums.end(), 0) << '\n';
    if (!fruits.empty())
        std::cout << "First fruit: " << *fruits.begin() << '\n';
    if (empty.begin() == empty.end())
        std::cout << "vector 'empty' is indeed empty.\n";
    //cbegin
    std::cout << "CBEGIN:" << endl;
    std::for_each(nums.rbegin(), nums.rend(), [](const int n) { std::cout << n << ' '; });
    std::cout << '\n';
    std::cout << "Sum of nums: "<< std::accumulate(nums.rbegin(), nums.rend(), 0) << '\n';
    if (!fruits.empty())
        std::cout << "First fruit: " << *fruits.rbegin() << '\n';
    if (empty.rbegin() == empty.rend())
        std::cout << "vector 'empty' is indeed empty.\n";
    //cend
    std::cout << "CEND: " << endl;
    Vektorius<int> myVector5{1, 2, 3, 4, 5};
  std::cout << "Elements of myVector using cend:";
  for (auto it = myVector5.cbegin(); it != myVector5.cend(); ++it) {
    std::cout << " " << *it;
  }
  std::cout << std::endl;
    //rbegin
    std::cout << "RBEGIN: " << endl;
     auto reverseBegin = myVector.rbegin();
     int value = *reverseBegin;
     std::cout << "Last element of myVector: " << value << std::endl;
    //rend
    std::cout << "REND: " << endl;
    std::cout << "Elements of myVector in reverse:";
    auto reverseEnd = myVector5.rend();
    for (auto iter = myVector5.rbegin(); iter != reverseEnd; ++iter) {
    int value = *iter;
    std::cout << " " << value;
  }
  std::cout << std::endl;
     //crbegin 
     std::cout << "CRBEGIN: " << endl;
     auto constReverseBegin = myVector5.crbegin();
  int value1 = *constReverseBegin;
  std::cout << "Last element of myVector (const): " << value << std::endl;
  // crend
  std::cout << "CREND: " << endl;
  auto constReverseEnd = myVector5.crend();
  std::cout << "Position before the first element of myVector (const): ";
  if (constReverseEnd != myVector5.crbegin()) {
    --constReverseEnd;
    std::cout << "Valid position";
  } else {
    std::cout << "Invalid position";
  }
  std::cout << std::endl;
  //assign
  std::cout << "ASSIGN: " << endl;
  Vektorius<char> characters;
    auto print_vector = [&]()
    {
        for (char c : characters)
            std::cout << c << ' ';
        std::cout << '\n';  
    };
 
    characters.assign(5, 'a');
    print_vector();
 
    const std::string extra(6, 'b');
    characters.assign(extra.begin(), extra.end());
    print_vector();
 
    characters.assign({'C', '+', '+', '1', '1'});
    print_vector();
    // push back
    std::cout << "PUSH_BACK: " << endl;
    Vektorius<string> letters;
 
    letters.push_back("abc");
    std::string s{"def"};
    letters.push_back(std::move(s));
 
    std::cout << "Vektorius `letters` holds: ";
    for (auto&& e : letters) std::cout << std::quoted(e) << ' ';
 
    std::cout << "\nMoved-from string `s` holds: " << std::quoted(s) << '\n';
    // pop_back
    std::cout << "POP_BACK: " << endl;
Vektorius<int> numbers4 = {1, 2, 3, 4, 5};

std::cout << "Original vector: ";
for (const auto& number : numbers4) {
    std::cout << number << " ";
}
std::cout << std::endl;

numbers4.pop_back();  // Remove the last element

std::cout << "Vector after pop_back: ";
for (const auto& number2 : numbers4) {
    std::cout << number2 << " ";
}
std::cout << std::endl;

    //swap
    std::cout << "SWAP: " << endl;
    Vektorius<int> g1 = {1, 2, 3, 4, 5};
    Vektorius<int> g2 = {10, 20, 30};
    std::cout << "Before swap:" << std::endl;
    std::cout << "g1: ";
    for (size_t i = 0; i <
     g1.size(); i++)
    std::cout << g1[i]  << " ";
    std::cout << endl;
    std::cout << "g2: ";
    for (size_t i = 0; i < g2.size(); i++)
    std::cout << g2[i]  << " ";
    std::cout << endl;
    g1.swap(g2);
    std::cout << "After swap:" << std::endl;
    std::cout << "g1: ";
    for (size_t i = 0; i < g1.size(); i++)
    std::cout << g1[i]  << " ";
    std::cout << endl;
    std::cout << "g2: ";
    for (size_t i = 0; i < g2.size(); i++)
    std::cout << g2[i]  << " ";
    std::cout << endl;
    // clear
    std::cout << "CLEAR: " << endl;
    Vektorius<int> sk = {1,5,8,9,20};
    std::cout << "vector pries clear: ";
    for (size_t i = 0; i < sk.size(); i++)
    std::cout << sk[i]  << " ";
    std::cout << endl;
    sk.clear();
    std::cout << "vector po clear: ";
    for (size_t i = 0; i < sk.size(); i++)
    std::cout << sk[i]  << " ";
    std::cout << endl;
    //insert 
    std::cout << "INSERT: " << endl;
    Vektorius<int> numbers5 = {1, 2, 3, 4, 5};

    std::cout << "Vector before insert: ";
    for (const auto& number : numbers5) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    numbers5.insert(numbers5.begin() + 2, 10);

    std::cout << "Vector after insert: ";
    for (const auto& number : numbers5) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
    //emplace ir emplace_back
    std::cout << "EMPLACE IR EMPLACE_BACK: " << endl;
    Vektorius<std::string> words;

    words.emplace_back("Hello");
    words.emplace(words.begin() + 1, "world");

    std::cout << "Vector contains " << words.size() << " element(s)." << std::endl;

    for (const auto& word : words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    //erase
    std::cout << "ERASE: " << endl;
    Vektorius<int> numbers7 = {1, 2, 3, 4, 5};

    std::cout << "Vector before erase: ";
    for (const auto& number : numbers7) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    numbers7.erase(numbers7.begin() + 2);

    std::cout << "Vector after erase: ";
    for (const auto& number : numbers7) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
auto startvector = std::chrono::high_resolution_clock::now();
unsigned int sz = 100000;  // 100000, 1000000, 10000000, 100000000
std::vector<int> v1;
for (int i = 1; i <= sz; ++i)
    v5.push_back(i);
// Finish measuring the time to fill v5
auto endvector = std::chrono::high_resolution_clock::now();
auto durationvector = std::chrono::duration_cast<std::chrono::microseconds>(endvector - startvector);

auto startVektorius = std::chrono::high_resolution_clock::now();
Vektorius<int> v2;
for (int i = 1; i <= sz; ++i)
    v2.push_back(i);
auto endVektorius = std::chrono::high_resolution_clock::now();
auto durationVektorius = std::chrono::duration_cast<std::chrono::microseconds>(endVektorius - startVektorius);

cout << "durationvector: " << durationvector.count() / 1000000.0 << " seconds. " << endl;
cout << "durationVektorius: " << durationVektorius.count()/ 1000000.0 << " seconds. " << endl;


}