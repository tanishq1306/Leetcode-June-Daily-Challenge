class Complex {
    public:
        int real;
        int img;
    
        Complex () {
            this -> real = 0;
            this -> img = 0;
        }
    
        Complex (int real, int img) {
            this -> real = real;
            this -> img = img;
        }
    
        static string multiply (Complex a, Complex b) {
            int x = a.real * b.real;
            int y = (a.real * b.img) + (a.img * b.real);
            int z = -1 * (a.img * b.img);
            
            x = x + z;
            string result;
            result += to_string(x);
            result += "+";
            result += to_string(y);
            result += "i";
            
            return result;
        }
    
        void set_real_part(string real_str) {
            this -> real = stoi(real_str);
        }
    
        void set_img_part(string img_str) {
            this -> img = stoi(img_str);
        }
    
        void formComplexNo(Complex &c, string num) {
            int i = 0;
            while (num[i] != '+') {
                i++;
            }

            c.set_real_part(num.substr(0, i));
            i++;
            
            int j = i + 1;
            while (num[j] != 'i') {
                j++;
            }
            
            c.set_img_part(num.substr(i, j));
        }
};

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        Complex c1, c2;
        
        c1.formComplexNo(c1, num1);
        c2.formComplexNo(c2, num2);
        
        string res = Complex::multiply(c1, c2);
        return res;        
    }
};
