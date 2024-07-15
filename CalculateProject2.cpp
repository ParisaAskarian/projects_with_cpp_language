#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>
using namespace std;
int power(int a, int b)
{
    int p = 1;
    for(int i = 0; i < b ; i++)
    {
        p *= a;
    }
    return p;
}
int findConst (string poly)
{
//it finds the constant number of a polynomial.
    int constant = 0;
    size_t start = 0;
    //a loop until the end of poly:
    while (start < poly.length()) {
        size_t end = poly.find_first_of("+-", start+ 1);

        if (end == string::npos)
        {
            end = poly.length();
        }
        string term;
        if (start==0 && poly[0]!='-')
            term = poly.substr(start, end-start);
        else
            term = poly.substr(start+1, end-(start+1));
        //This checks if the current term contains an 'x' variable:
        size_t xPosition = term.find('x');
        //If the term doesn't contain an 'x' (constant term):
        if (xPosition == string::npos) {
            if(poly[start] == '-')
            {
                constant = -(stoi(term));
            }
            else
            {
                constant = stoi(term);
            }
        }
        start = end;
    }
    return constant;
}
int findConstInteg (string poly)
{
//it finds the constant number of a polynomial.
    int constant = 0;
    size_t start = 0;
    //a loop until the end of poly:
    while (start < poly.length()) {
        size_t end = poly.find_first_of("+-", start+ 1);

        if (end == string::npos)
        {
            end = poly.length();
        }
        string term;
        if (start==0 && poly[0]!='-')
            term = poly.substr(start, end-start);
        else
            term = poly.substr(start+1, end-(start+1));
        //This checks if the current term contains an 'x' variable:
        size_t xPosition = term.find('x');
        //If the term doesn't contain an 'x' (constant term):
        if (xPosition == string::npos) {
            constant = stoi(term);
        }
        start = end;
    }
    return constant;
}
int CoEfficient( const string &poly, int start, int end)
{
//it returns coefficient (zarib) of x; (end is the place of x)
    string substring = poly.substr(start, end - start);
    try
    {
        int result = stoi(substring);
        return result;
    }
    catch (const std::invalid_argument& e)
    {
        // Handle invalid argument (e.g., print an error message)
        cerr << "Invalid coefficient: " << substring << endl;
        return 0; // Return a default value or handle the error as needed
    }
}
int powr( const string &poly, int i)
{
//it returns power of x; (i is the place of x)
    int power=0, start=i+2;
    // ASCII Val converter
    while ( poly[i+2] >= 48 && poly[i+2] <= 57)
        i++;
    for( int j=start; j<=i+1; j++)
        power=power*10+ (poly[j]-'0');
    return power;
}
int count( string A,int n)
{
//It counts how many "x" we have.
    int i= 0;
    int k = 0;
    for( int j = 0 ; j<n; j++)
    {
        if( A[j] == '+' || A[j] == '-')
        {
            i = i+1;
        }
        else if( A[j] == 'x')
        {
            k = k+1;
        }
    }
    if( k == i)
    {
        if(findConst(A) != 0)
        {
            return i+1;
        }
        else
        {
            return i;
        }
    }
    else if( i > k)
    {
        return i;
    }
    else
    {
        return i+1;
    }
}
struct tam
{
//It's a box of new data that it has a coefficient and an exponent
    int coef;
    int exp;
};
struct poly
{
//It's a box of data that it has a size and a pointer of tams data
    int n;
    struct tam*t;
};
poly change( string B)
{
//This function return a poly that have the coefficients and exponents of A inside it
    string A(B.size()+1,'\0');
    for(int i = 0; i < B.size(); i++)
    {
        A[i+1] = B[i];
    }
    int d = B.size();
    int c= A.size();
    poly p;
    p.n = count(B,d);
    p.t = new tam[p.n];
    int i= 0;
    while (  i< p.n )
    {
        int k=1;
        for( int j=0; j < c; j++)
        {
            if ( A[j] == 'x')
            {
                if(A[j-1] == '\0')
                {
                    p.t[i].coef = 1;
                    if( A[j+1] != '^')
                    {
                        p.t[i++].exp = 1;
                    }
                    else
                    {
                        p.t[i++].exp = powr(A,j);
                    }
                }
                else if(A[j-1] == '-')
                {
                    p.t[i].coef = -1;
                    if( A[j+1] != '^')
                    {
                        p.t[i++].exp = 1;
                    }
                    else
                    {
                        p.t[i++].exp = powr(A,j);
                    }
                }
                else if(A[j-1] == '+')
                {
                    p.t[i].coef = 1;
                    if( A[j+1] != '^')
                    {
                        p.t[i++].exp = 1;
                    }
                    else
                    {
                        p.t[i++].exp = powr(A,j);
                    }
                }
                else
                {
                    p.t[i].coef = CoEfficient(A, k,j);
                    if(A[j+1] != '^' || j == c-1)
                    {
                        p.t[i++].exp = 1;
                    }
                    else
                    {
                        p.t[i++].exp = powr(A,j);
                    }
                }


            }

            else if( (A[j] == '+') || (A[j] == '-'))
            {
                k = j;
                continue;
            }
        }
        if(findConst(B) != 0)
        {
            p.t[i].exp = 0;
            p.t[i++].coef = findConst(B);
        }
    }
    return p;
}
int power (string term)
{
    int power;
    size_t xPos = term.find('x');
    if(xPos==term.length()-1)
        power=1;
    else
    {
        string powerStr = term.substr(xPos+2); // Skip 'x^'
        stringstream(powerStr) >> power; //it works like stoi.
    }
    return power;
}
int coEff (string term)
{
    int coeff; //coefficient (zarib).
    size_t xPos = term.find('x');
    if(xPos!=string::npos) {
        if(xPos==0)
            coeff=1;
        else
        {
            string coeffStr = term.substr(0, xPos);
            stringstream(coeffStr) >> coeff;
        }
        return coeff;
    }
}
void Sum(string A,string B)
{
//This function sum two polynomials
    poly P2 = change(B);
    int lengthB = B.size();
    P2.n = count(B,lengthB);
    poly P1 = change(A);
    int lengthA = A.size();
    P1.n= count(A,lengthA);
    poly P3;
    P3.t = new tam[P3.n];
    int i=0, j=0,k=0;
    while ( i<P1.n && j<P2.n)
    {
        if( P2.t[j].exp > P1.t[i].exp)
        {
            P3.t[k++] = P2.t[j++];
        }
        else if( P1.t[i].exp > P2.t[j].exp)
        {
            P3.t[k++] = P1.t[i++];
        }
        else
        {
            P3.t[k].exp = P1.t[i].exp;
            P3.t[k++].coef = P1.t[i++].coef + P2.t[j++].coef;
        }
    }
    while ( i < P1.n)
    {
        P3.t[k++] = P1.t[i++];
    }
    while ( j < P2.n)
    {
        P3.t[k++] = P2.t[j++];
    }
    P3.n = k;
    cout<<"Sum=";
    for(int r = 0; r < P3.n; r++)
    {
        if(P3.t[r].coef == 0)
        {
            if(P3.t[r+1].coef < 0)
            {
                continue ;
            }
            else if ( r != 0 && (r+1)<P3.n)
            {
                if(P3.t[r+1].coef != 0)
                {
                    cout << '+';
                    continue ;
                }
                else
                {
                    continue;
                }
            }
            else if ( P3.n == 1)
            {
                cout << 0;
            }
            else if( r == 0)
            {
                continue;
            }
            else if( r == (P3.n - 1))
            {
                if( P3.t[r-1].coef == 0 && (r-1) == 0)
                {
                    cout << 0;
                }
                else
                {
                    continue;
                }
            }
        }
        else if( P3.t[r].exp == 0 )
        {
            cout << P3.t[r].coef;
        }
        else if(P3.t[r].exp == 1)
        {
            if(P3.t[r].coef == 1)
            {
                cout <<"x";
            }
            else if (P3.t[r].coef == -1)
            {
                cout << "-x";
            }
            else
            {
                cout << P3.t[r].coef <<"x";
            }
        }
        else
        {
            if(P3.t[r].coef == 1)
            {
                cout << "x^" << P3.t[r].exp;
            }
            else if(P3.t[r].coef == -1)
            {
                cout << "-x^" << P3.t[r].exp;
            }
            else
            {
                cout<< P3.t[r].coef << "x^" << P3.t[r].exp;
            }
        }
        if(k > 1 && P3.t[r+1].coef > 0)
        {
            if(r+1 < k)
            {
                cout<< "+";
            }
        }

    }
    delete [] P3.t;
}
void Minus(string A,string B)
{
//This function sum two polynomials
    poly P2 = change(B);
    int lengthB = B.size();
    P2.n = count(B,lengthB);
    poly P1 = change(A);
    int lengthA= A.size();
    P1.n= count(A,lengthA);
    poly P3;
    P3.n = max(P1.n,P2.n);
    P3.t = new tam[P3.n];
    int i=0, j=0,k=0;
    while ( i<P1.n && j<P2.n)
    {
        if( P2.t[j].exp > P1.t[i].exp)
        {
            P3.t[k].exp = P2.t[j].exp;
            P3.t[k++].coef = -(P2.t[j++].coef);
        }
        else if( P1.t[i].exp > P2.t[j].exp)
        {
            P3.t[k++] = P1.t[i++];
        }
        else
        {
            P3.t[k].exp = P1.t[i].exp;
            P3.t[k++].coef = P1.t[i++].coef - P2.t[j++].coef;
        }
    }
    while ( i < P1.n)
    {
        P3.t[k++] = P1.t[i++];
    }
    while ( j < P2.n)
    {
        P3.t[k].exp = P2.t[j].exp;
        P3.t[k++].coef = -(P2.t[j++].coef);
    }
    P3.n = k;
    cout<<"Minus=";
    for(int r = 0; r < P3.n; r++)
    {
        if(P3.t[r].coef == 0)
        {
            if(P3.t[r+1].coef < 0)
            {
                continue ;
            }
            else if ( r != 0 && (r+1)<P3.n)
            {
                if(P3.t[r+1].coef != 0)
                {
                    cout << '+';
                    continue ;
                }
                else
                {
                    continue;
                }
            }
            else if ( P3.n == 1)
            {
                cout << 0;
            }
            else if( r == 0)
            {
                continue;
            }
            else if( r == (P3.n - 1))
            {
                if( P3.t[r-1].coef == 0 && (r-1) == 0)
                {
                    cout << 0;
                }
                else
                {
                    continue;
                }
            }
        }
        else if( P3.t[r].exp == 0)
        {
            cout << P3.t[r].coef;
        }
        else if(P3.t[r].exp == 1)
        {
            if(P3.t[r].coef == 1)
            {
                cout <<"x";
            }
            else if (P3.t[r].coef == -1)
            {
                cout << "-x";
            }
            else
            {
                cout << P3.t[r].coef <<"x";
            }
        }
        else
        {
            if(P3.t[r].coef == 1)
            {
                cout << "x^" << P3.t[r].exp;
            }
            else if(P3.t[r].coef == -1)
            {
                cout << "-x^" << P3.t[r].exp;
            }
            else
            {
                cout<< P3.t[r].coef << "x^" << P3.t[r].exp;
            }
        }
        if(k > 1 && P3.t[r+1].coef > 0)
        {
            if(r+1 < k)
            {
                cout<< "+";
            }
        }

    }
    delete [] P3.t;
}
void integral (string poly)
{
//polynomial includes several terms [start,end]. each has a coefficient, x position, and power.
    cout<<"Integral=";
    size_t start = 0;
    if (poly[0]=='-')
        cout<<"-";
    while (start < poly.length()) {
        size_t end = poly.find_first_of("+-", start + 1);
        if (end == string::npos)
            end = poly.length();
        string term;
        if (start==0 && poly[0]!='-')
            term = poly.substr(start, end-start);
        else
            term = poly.substr(start+1, end-(start+1));
        int pow= power(term)+1;
        if (pow==1)
            break;
        int co= coEff(term);
        cout<<"("<<co<<"/"<<pow<<")x^"<<pow;
        if (end<=poly.length())
        {   char sign=poly[end];
            cout<<sign;
        }
        start=end;
    }
    if(findConstInteg(poly)!=0)
        cout<<"("<<findConstInteg(poly)<<"/1)x+";
    cout<<"c";
    return;
}
void Find( string A, int n)
{
    poly P = change(A);
    int m = A.size();
    P.n = count(A, m);
    long long f = 0;
    for(int i = 0; i < P.n ; i++)
    {
        f += power(n,P.t[i].exp) * P.t[i].coef;
    }
    cout<< "Find="<<f;
    delete [] P.t;
}
void derivative (string In)
{
    string ans, copy_In;
    int pow, coe;
    copy_In = In;
    // derivative of a fixed number=0
    if (In.find('x') == string::npos)
        ans = '0';

    // Differentiation
    while (In.find('x') != string::npos)
    {
        int pointer = 0;

        if (In[0] == 'x')
            coe = 1;
        else if ((In[0] == '-' || In[0] == '+') && In[1] == 'x')
            coe = 1;
        else
            coe = stoi(In.substr(0, In.find('x')));

        if (In.find('^') != string::npos)
        {
            for (int i = In.find('^') + 1; i < In.size(); i++)
            {
                if (In[i] == '-' || In[i] == '+')
                {
                    pointer = i;
                    break;
                }
                else
                    pointer = In.size();
            }

            pow = stoi(In.substr(In.find('^') + 1, (pointer - In.find('^')) - 1));
        }
        else
        {
            ans += to_string(abs(coe));
            break;
        }
        if (pow == 2)
            ans += to_string(abs(coe * pow)) + "x" + In[pointer];
        else
            ans += to_string(abs(coe * pow)) + "x^" + to_string(pow - 1) + In[pointer];

        In = In.substr(pointer, In.size());
    }
    if (copy_In[0] == '-' && copy_In.find('x') != string::npos)
        ans = '-' + ans;
    if (ans.back() == '+' || ans.back() == '-')
        ans.pop_back();

    cout << "Derivative=" << ans;
    return;
}
int i;
int justOne=0;
string poly;
void findAnswer(string text)
{
    if (text.find("Define:") != string::npos) {
        if (justOne==0) {
            poly= text.substr(7);
            justOne++;
        }
        else
            cout << "Error: unknown command!"<<endl;
        return;
    }

    size_t sumPos = text.find("Sum:");
    if (sumPos != string::npos) {
        cout<<"";
        string sum= text.substr(4);
        Sum(poly, sum);
        cout<<endl;
        return;
    }

    size_t minusPos = text.find("Minus:");
    if (minusPos != string::npos) {
        string minus=text.substr(6);
        Minus(poly, minus);
        cout<<endl;
        return;
    }
    if (text.find("Derivative") != string::npos) {
        derivative(poly);
        cout<<endl;
        return;
    }
    if (text.find("Integral") != string::npos) {
        integral(poly);
        cout<<endl;
        return;
    }
    size_t findPos = text.find("Find:");
    if (findPos != string::npos) {
        string find=text.substr(5);
        int number= stoi(find);
        Find(poly, number);
        cout<<endl;
        return;
    }
    cout << "Error: unknown command!"<<endl;
}
int main() {
    // Create a vector to store the lines
    vector<string> lines;
    string line;
    while (getline(cin, line)) {
        if (line == "End") {
            break;
        }
        //push_back() function is used to insert new value into the vector increasing size by 1. 
        lines.push_back(line);
    }
    // Separate each line into separate strings and save them to the vector
    vector<string> separatedLines;
    // auto type: automatically detects a data type.
   //this process helps to separate lines:
    for (const auto& l : lines) {
        istringstream iss(l);
        //istringstream is a string class which is used to change formats. (sstream library)
        string word;
        while (iss >> word) {
            separatedLines.push_back(word);
        }
    }
    string text;
    i=0;
    string lastLine = lines.back();
    while (lastLine!= separatedLines[i-1])
    {   text = separatedLines[i];
        findAnswer(text);
        i++;
    }

    return 0;
}
/*atention!: for give this program input:
Define:     
Sum/Mines:     
Integral     
Derivative
End
*/
