#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Math {
    private:
        double m_a;
        double m_b;

    public:
        string variables[2] = {"a", "b"};

        Math(double a, double b) {
            m_a = a;
            m_b = b;
            cout << this->toString() << endl;
		}

        void setA(double a) {
            m_a = a;
            cout << "a = " << m_a << endl;
        }

        void setB(double b) {
			m_b = b;
            cout << "b = " << m_b << endl;
		}

        int add() const {
			return m_a + m_b;
		}

        int subtract() const {
			return m_a - m_b;
		}

        int multiply() const {
			return m_a * m_b;
		}

        int divide() const {
            if (m_b == 0) {
				cout << "Error: Division by zero" << endl;
				return 0;
			}
			return m_a / m_b;
		}

        int faculty() const {
            if (m_a < 0 || ceil(m_a) != m_a) {
                cout << "Error: Faculty of negative number or non-integer" << endl;
                return 0;
            }

			int result = 1;
            for (int i = 1; i <= m_a; i++) {
                result *= i;
            }
            return result;
        }

        double power() const {
			double result = 1;
            for (int i = 1; i <= m_b; i++) {
				result *= m_a;
			}
			return result;
		}

        string toString() const {
            return "a = " + to_string(m_a) + ", b = " + to_string(m_b);
        }

        static int add(double a, double b) {
            return a + b;
        }
};

int main() {
    // Initialize Math object
    Math math(10, 5);

    // Test add, subtract, divide and multiply methods
    cout << math.variables[0] << " + " << math.variables[1] << " = " << math.add() << endl;
    cout << math.variables[0] << " - " << math.variables[1] << " = " << math.subtract() << endl;
    cout << math.variables[0] << " / " << math.variables[1] << " = " << math.divide() << endl;
    cout << math.variables[0] << " * " << math.variables[1] << " = " << math.multiply() << endl;

    // Test setA and setB methods
    math.setA(5);
    math.setB(2);

    // Test faculty and power methods
    cout << math.variables[0] << "! = " << math.faculty() << endl;
    cout << math.variables[0] << " ^ " << math.variables[1] << " = " << math.power() << endl;

    // Initialize Math pointer array
    Math* mathArray[2] = {new Math(10, 5), new Math(5, 0)};

    // Test toString method
    cout << (*mathArray[0]).toString() << endl;
    cout << mathArray[0]->toString() << endl;

    // Initialize Math pointer vector
    vector<Math*> mathVector = {new Math(10, 5), new Math(5, 0)};

    // Print first element of Math vector
    cout << mathVector.at(0)->toString() << endl;

    // Add new element to Math vector
    mathVector.push_back(new Math(5, 2));

    // Test static method
    cout << Math::add(1, 2) << endl;

	return 0;
}