#include <iostream>

class Array2Linear
{
    int sizeY;
    int sizeX;
    int* data;
    int index2D(int x, int y) const{
        return y * sizeX + x;
    }
    int index2D(int x, int y,int sizeXP){
        return y * sizeXP + x;
    }

public:

    void addColumn(int columnPos, int* newColumn = nullptr){
        int* newData{new int[sizeY * (sizeX + 1)]}
        for(int i{}; i <= sizeX; i++){
            for(int j{}; j<+ sizeY;i++){

            }
        }
        delete[] data;
        data = newData;
        sizeX++;
    }

    Array2Linear(int sY, int sX)
        // : sizeY{sY}, sizeX{sX}, data{new int*[sizeY]}
        : sizeY{sY}, sizeX{sX}, data{new int[sizeY * sizeX]}
    {}

    int operator()(int y,int x)const { 
        return *(data + index2D(y,x));
    }

    int& operator()(int y,int x){
        return *(data + index2D(y,x));
    }

    void deleteColumn(int columnPos){
        sizeX--;
        int* newData {new int[sizeX * sizeY]};

        for( int i{}; i < sizeY; i++){
            for (int j{};j < sizeX; j++){
                *(newData + index2D(i,j)) = *(data+index2D(i,j+(j>=columnPos),sizeX + 1));
            }
        }
        delete[] data;
        data = newData;
    }

    void print() const
    {
        for (int i{}; i < sizeY; i++)
        {
            for (int j{}; j < sizeX; j++)
            {
                //std::cout << data[i][j] << " ";
                std::cout << (*this)(i,j) << " ";
            }
            std::cout << "\n";
        }        

    }
    ~Array2Linear()
    {
        // for (int i{}; i < sizeY; i++)
        // {
        //     delete[] data[i];
        // }
        // delete[] data;
        //delete[] data[0];
        delete[] data;
    }

};