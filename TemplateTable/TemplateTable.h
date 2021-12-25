#include <iostream>
#include <exception>

template<class T1, class T2>
struct Pair {
    T1 key;
    T2 data;
    Pair();
    Pair(T1 _key, T2 _data);
};

template<class T1, class T2>
Pair<T1, T2>::Pair(): key(), data() {}

template<class T1, class T2>
Pair<T1, T2>::Pair(T1 _key, T2 _data): key(_key), data(_data) {}

template<class T1, class T2>
std::istream &operator>>(std::istream &in, Pair<T1, T2> &p) {
    in >> p.key >> p.data;
    return in;
}

template<class T1, class T2>
std::ostream &operator<<(std::ostream &out, Pair<T1, T2> &p) {
    out << p.key << p.data;
    return out;
}

template<class T1, class T2>
class TabIterator {
private:
    Pair<T1, T2> *pairs;
public:
    TabIterator();
    TabIterator(Pair<T1, T2> *_pairs);
    Pair<T1, T2>& operator*();
    TabIterator &operator++();
    bool operator!=(const TabIterator<T1, T2> &tabIterator) const;
    bool operator==(const TabIterator<T1, T2> &tabIterator) const;
};

template<class T1, class T2>
TabIterator<T1, T2>::TabIterator(): pairs(nullptr) {}

template<class T1, class T2>
TabIterator<T1, T2>::TabIterator(Pair<T1, T2> *_pairs): pairs(_pairs) {}

template<class T1, class T2>
Pair<T1, T2> &TabIterator<T1, T2>::operator*() {
    if (pairs) return *pairs;
    throw std::invalid_argument("Wrong iterator");
}

template<class T1, class T2>
TabIterator<T1, T2> &TabIterator<T1, T2>::operator++() {
    ++pairs;
    return *this;
}

template<class T1, class T2>
bool TabIterator<T1, T2>::operator!=(const TabIterator<T1, T2> &tabIterator) const {
    return pairs != tabIterator.pairs;
}

template<class T1, class T2>
bool TabIterator<T1, T2>::operator==(const TabIterator<T1, T2> &tabIterator) const {
    return pairs == tabIterator.pairs;
}

template<class T1, class T2>
class Table {
private:
    static const int QUOTA = 10;
    int counter;
    Pair<T1, T2> *tableArray;
public:
    Table();
    Table(const Table<T1, T2> &_table);
    Table(int _counter, const Pair<T1, T2> *_tableArray);
    ~Table();
    int getCounter();
    void push(const Pair<T1, T2> &p);
    T2 &find(const T1 &search);
    friend class TabIterator<T1, T2>;
    TabIterator<T1, T2> begin();
    TabIterator<T1, T2> end();
};

template<class T1, class T2>
Table<T1, T2>::Table(): counter(0), tableArray(nullptr) {}

template<class T1, class T2>
Table<T1, T2>::Table(const Table<T1, T2> &_table): counter(_table.counter) {
    if (counter == 0) tableArray = nullptr;
    else {
        tableArray = new Pair<T1, T2>[QUOTA * ((counter - 1) / QUOTA + 1)];
        for (int i = 0; i < counter; i++)
            tableArray[i] = _table.tableArray[i];
    }
}

template<class T1, class T2>
Table<T1, T2>::Table(int _counter, const Pair<T1, T2> *_tableArray): counter(_counter) {
    if (counter == 0) tableArray = nullptr;
    else {
        tableArray = new Pair<T1, T2>[QUOTA * ((counter - 1) / QUOTA + 1)];
        for (int i = 0; i < counter; i++)
            tableArray[i] = _tableArray[i];
    }
}

template<class T1, class T2>
Table<T1, T2>::~Table() {
    counter = 0;
    delete[] tableArray;
}

template<class T1, class T2>
int Table<T1, T2>::getCounter() {
    return counter;
}

template<class T1, class T2>
void Table<T1, T2>::push(const Pair<T1, T2> &p) {
    if (counter % QUOTA == 0) {
        Pair<T1, T2> *tempArray;
        tempArray = new Pair<T1, T2>[QUOTA * ((counter - 1) / QUOTA + 1)];
        for (int i = 0; i < counter; i++)
            tempArray[i] = tableArray[i];
        delete[] tableArray;
        tempArray[counter++] = p;
        tableArray = tempArray;
    }
    else {
        tableArray[counter++] = p;
    }
}

template<class T1, class T2>
T2& Table<T1, T2>::find(const T1 &search) {
    for (TabIterator<T1, T2> it = begin(); it != end(); ++it) {
        if (search == (*it).key) return (*it).data;
    }
}

template<class T1, class T2>
TabIterator<T1, T2> Table<T1, T2>::begin() {
    return TabIterator<T1, T2>(tableArray);
}

template<class T1, class T2>
TabIterator<T1, T2> Table<T1, T2>::end() {
    return TabIterator<T1, T2>(tableArray + counter);
}