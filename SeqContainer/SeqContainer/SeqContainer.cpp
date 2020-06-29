//В контейнере заменить максимальный элемент на первый элемент в контейнере.
#include <iostream>
#include <random>
#include <bitset>
#include <vector>

using namespace std;

void generateElements(vector<bitset<32>>& bitContainer);
void printElements(vector<bitset<32>>& bitContainer, string title);
void changeMaxElement(vector<bitset<32>>& bitContainer);
bool BitComp(bitset<32>& l, bitset<32>& r);
void printElement(vector<bitset<32>>& bitContainer, int index);

const int CONT_SIZE = 20;

int main()
{
    setlocale(LC_ALL, "Russian");

    vector<bitset<32>> bitContainer;

    int index;

    generateElements(bitContainer);
    printElements(bitContainer, "Элементы контейнера");

    changeMaxElement(bitContainer);
    printElements(bitContainer, "Контейнер после изменения");

    cout << "\nВведите индекс элемента: ";
    cin >> index;
    printElement(bitContainer, index);
    
}

void generateElements(vector<bitset<32>>& bitContainer)
{
    random_device rd;
    mt19937 gen(rd());

    int newValue = gen();

    for (int i = 0; i < CONT_SIZE; i++)
    {
        int value = gen();

        bitContainer.push_back(value);
    }
}

void printElements(vector<bitset<32>>& bitContainer, string title)
{
    vector<bitset<32>>::iterator it;

    cout << "\n||" << title << ":" <<  "||" << endl;
    
    for (it = bitContainer.begin(); it != bitContainer.end(); it++)
    {
        bitset<32> tmp = *it;
        cout << "[" << distance(bitContainer.begin(), it) << "]\t" << *it << " | " << hex << tmp.to_ulong() << dec << " | " << tmp.to_ulong() << endl;
    }
}

void changeMaxElement(vector<bitset<32>>& bitContainer)
{
    vector<bitset<32>>::iterator itMaxElement = max_element(bitContainer.begin(), bitContainer.end(), BitComp);
    vector<bitset<32>>::iterator itFirstElement = bitContainer.begin();

    cout << "\nМаксимальный элемент - " << (*itMaxElement).to_ulong() << endl;
    cout << "Замена: " << (*itMaxElement).to_ulong() << " -> " << (*itFirstElement).to_ulong() << endl;

    bitset<32> tmp = *itFirstElement;

    *itMaxElement = tmp;
    
}

bool BitComp(bitset<32>& l, bitset<32>& r)
{
    return int(l.to_ulong()) < int(r.to_ulong());
}

void printElement(vector<bitset<32>>& bitContainer, int index)
{
    try
    {
        bitset<32> tmp = bitContainer.at(index);
        vector<bitset<32>>::iterator it;
        cout << "Элемент [" << index << "] = " << tmp << " | " << tmp.to_ulong() << endl;
        
    }
    catch (out_of_range)
    {
        cout << "Out of range" << endl;
    }
}