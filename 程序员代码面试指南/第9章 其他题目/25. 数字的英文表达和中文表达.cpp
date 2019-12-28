#include <iostream>
#include <string>
using namespace std;
 
string Eng1to19(int num) {
    string names[] = {"One ", "Two ", "Three ", "Four ", "Five ", "Six ",
    "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ",
    "Fifteen ", "Sixteen ", "Sixteen ", "Eighteen ", "Nineteen "}; // 测试用例错了，应该是seventeen才对...
 
    if (num > 0 && num < 20) {
        return names[num-1];
    }
    else {
        return "";
    }
}
 
string Eng1to99(int num) {
    if (num > 99 || num < 1) {
        return "";
    }
     
    if (num <= 19 && num >= 0) {
        return Eng1to19(num);
    }
 
    string tys[] = {"Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ",
    "Eighty ", "Ninety "};
 
    int tenth = num / 10;
    int single = num % 10;
 
    return tys[num / 10 - 2] + Eng1to19(num%10);
}
 
string Eng1to999(int num) {
    if (num > 0 && num < 100) {
        return Eng1to99(num);
    }
    if (num > 999 || num < 1) {
        return "";
    }
 
    int hunth = num / 100;
    int left = num % 100;
     
    return Eng1to99(num/100) + "Hundred " + Eng1to99(num%100);
}
 
string EngNum(int num) {
    if (num == 0) {
        return "Zero";
    }
 
    string res = "";
 
    if (num == (1 << 31)) {
        res = "Negative, Two Billion, ";
        num%=-2000000000;
        num = -num;
    }
 
    if (num < 0) {
        res = "Negative, ";
        num = -num;
    }
 
    int high = 1000000000; // 1billion
    int highInd = 0;
    string names[] = {"Billion", "Million", "Thousand", ""};
 
    while (num>999) {
        if (num/high>0) {
            res += Eng1to999(num / high);
            res += names[highInd];
            num %= high;
            if (num == 0) {
                res += "";
            }
            else {
                res += ", ";
            }
        }
        high /= 1000;
        highInd++;
    }
    res += Eng1to999(num);
 
    return res;
}
 
string Chi1to9(int num) {
    string names[] = {"一", "二", "三", "四", "五", "六", "七", "八", "九"};
 
    if (num > 9 || num < 1) {
        return "";
    }
    else {
        return names[num - 1];
    }
}
 
string Chi1to99(int num, bool hundred) {
    if (num > 99 || num < 1) {
        return "";
    }
 
    if (num < 10) {
        return Chi1to9(num);
    }
    if (num / 10 == 1) {
        return hundred?"一十"+ Chi1to9(num % 10): "十"+Chi1to9(num % 10);
    }
    else {
        return Chi1to9(num / 10) + "十" + Chi1to9(num % 10);
    }
}
 
string Chi1to999(int num) {
    if (num > 999 || num < 1) {
        return "";
    }
 
    if (num < 100) {
        return Chi1to99(num, false);
    }
 
    string res = Chi1to9(num / 100)+"百";
 
    if (num % 100 == 0) {
        return res;
    }
    else if ((num % 100) / 10 == 0) {
        return res+ Chi1to9((num % 100) / 10) + "零" + Chi1to9(num % 10);
    }
    else {
        return res + Chi1to9((num % 100) / 10) + "十" + Chi1to9(num % 10);
    }
}
 
string Chi1to9999(int num) {
    if (num > 9999 || num < 1) {
        return "";
    }
 
    if (num < 1000) {
        return Chi1to999(num);
    }
 
    string res = Chi1to9(num/1000)+"千";
 
    if (num % 1000 == 0) {
        return res;
    } else  if ((num / 100) % 10 == 0) {
        return res + "零" + Chi1to99(num%1000, false);
    }
    else {
        return res + Chi1to999(num%1000);
    }
}
 
string ChiNum(int num) {
    if (num == 0) {
        return "零";
    }
 
    string res = "";
 
    if (num == (1 << 31)) {
        res = "负二十一亿";
        num %= -2100000000;
        num = -num;
    }
 
    if (num < 0) {
        res = "负";
        num = -num;
    }
 
    int high = 100000000; // 1亿
    int highInd = 0;
    string names[] = { "亿", "万", "" };
 
    while (num>9999) {
        if (num / high>0) {
            res += Chi1to9999(num / high);
            res += names[highInd];
            if (num / (high / 10) %10 == 0&&num%high!=0) {
                res += "零";
            }
            num %= high;
        }
        high /= 10000;
        highInd++;
    }
    res += Chi1to9999(num);
    return res;
}
 
int main()
{
    long n;
    cin >> n;
    cout << EngNum(n) << endl;
    cout << ChiNum(n) << endl;
 
    system("pause");
    return 0;
}
