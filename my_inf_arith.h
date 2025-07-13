#include<bits/stdc++.h>
using namespace std;

namespace InfiniteArithmetic
{
    class integer
    {
        private:
            string int_num;
        public:
            integer();
            integer(string s);
            integer(const integer &copy);
            ~integer();

            void parse(const string &s);

            string operator+(const integer &s) const;
            string operator-(const integer &s) const;
            string operator*(const integer &s) const;
            string operator/(const integer &s) const;

    };

    class Float
    {
        private:
            string float_num;
        public:
            Float();
            Float(string s);
            Float(const Float &copy);
            ~Float();

            void parse(const string &s);

            string operator+(const Float &s) const;
            string operator-(const Float &s) const;
            string operator*(const Float &s) const;
            string operator/(const Float &s) const;
            
    };
}
