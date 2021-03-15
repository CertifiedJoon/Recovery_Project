#include <iostream>
#include <memory>

int main () {
	std::unique_ptr<int> p(new int (42));
	std::unique_ptr<int> q = p;
}

/*
12_16.cpp: In function 'int main()':
12_16.cpp:6:27: error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = int; _Dp = std::default_delete<int>]'
    6 |  std::unique_ptr<int> q = p;
      |                           ^
In file included from /usr/include/c++/9/memory:80,
                 from 12_16.cpp:2:
/usr/include/c++/9/bits/unique_ptr.h:411:7: note: declared here
  411 |       unique_ptr(const unique_ptr&) = delete;
      |       ^~~~~~~~~~
*/