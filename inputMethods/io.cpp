#include <fstream>
#include <sstream>
#include <string>

//чтение интов из файла и запись их в другой файл
//include fstream
void readFromFile(std::string in, std::string out){
    std::ifstream f(in); // Экземпляр класса ifstream
    std::ofstream o(out);

    if(f.is_open()){ // if the file is opened
        while(!f.eof()){
            int x;
            f >> x; //в переменную Х направляем поток ввода
            o << x << ' '; // заполняем output.txt
        }
        o << '\n';
        f.close();
        o.close();
    }
}

//чтение строки из файла до разделителя
//include <string>
//include <sstream>
void readString(std::string in, std::string out){
    std::ifstream f(in);
    std::ofstream o(out);

    if(f.is_open()){
        std::string s; //сюда считаем из потока "f"
        char delim = ' '; // разделитель, default='\n'
        std::getline(f,s,delim); //см https://cplusplus.com/reference/string/string/getline/
        //std::cout << "s=" << s << ";\n";
        o << s; //вывод строки в поток "o"
        f.close();
        o.close();
    }
}