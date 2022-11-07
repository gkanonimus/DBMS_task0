#include <iostream>
#include <random>

using namespace std;

/**
 * \brief Get size if the array
 * \return Size_t size of array
 * \exception Function throws exception invalid_argument if array has invalid size
 */
size_t get_size();

/**
 * \brief Fills the array with pseudo-random values
 * \param Accepts a pointer to array
 * \param Accepts size of the array
 */
void fill_array(unsigned char*& values, const size_t size);

/**
* \brief Print array in size_t and char types
* \param Accepts a pointer to array with pseudo-random unsigned chars
* \param Accepts size of the array
*/
void print_array(unsigned char* values, const size_t size);

/**
* \brief Calculates the arithmetic average value and prints it
* \param Accepts a pointer to array with pseudo-random unsigned chars
* \param Accepts size of the array
* \return Arithmetic mean integer type
*/
size_t algo(unsigned char* values, const size_t size);

/**
* \brief Removes array and frees memory
* \param Accepts a pointer to array with pseudo-random chars
*/
void remove_array(unsigned char*& values);

int main() {
    size_t tmp_size;
    try {
        tmp_size = get_size();
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what();
        return 1;
    }

    const size_t size = tmp_size;

    unsigned char* values = new unsigned char[size];
    fill_array(values, size);
    print_array(values, size);

    size_t result = algo(values, size);
    cout << "\nResult in char is " << static_cast<char>(result) << "\nResult in integer value is " << result << endl;
    remove_array(values);
    return 0;
}

size_t get_size() {
    int size;
    cout << "Input size of array: ";
    cin >> size;

    if (size <= 0) {
        throw invalid_argument("The array size must be greater than 0");
    }
    return static_cast<size_t>(size);
}

void fill_array(unsigned char*& values, const size_t size) {
    const size_t lower = 0;
    const size_t upper = 255;
    std::random_device rd;
    mt19937 gen(rd());
    std::uniform_int_distribution<> dist(lower, upper);
    for (size_t i = 0; i < size; i++) {
        values[i] = dist(gen);
    }
}

void print_array(unsigned char* values, const size_t size) {
    if (values == nullptr) throw invalid_argument("The array size must be greater than 0\n");

    const auto visual = 25;
    cout << "\nYour array in char is:\n";
    for (size_t i = 0; i < size; i++) {
        if (i % visual == 0 && i != 0) cout << endl;
        cout << values[i] << " ";
    }
    cout << "\nYour array in integer value is:\n";
    for (size_t i = 0; i < size; i++) {
        if (i % visual == 0 && i != 0) cout << endl;
        cout << static_cast<size_t>(values[i]) << " ";
    }
}

size_t algo(unsigned char* values, const size_t size) {
    if (values == nullptr) throw invalid_argument("The array size must be greater than 0\n");

    size_t res = 0;
    for (size_t i = 0; i < size; i++) {
        res += values[i];
    }
    return res / size;
}

void remove_array(unsigned char*& values) {
    if (values != nullptr) {
        delete[] values;
        values = nullptr;
    }
}