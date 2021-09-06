#include <bits/stdc++.h>

using namespace std;

class DataSource
{
public:
    virtual void writeData(string contents) = 0;
    virtual string readData() = 0;
};

class FileSourceData : public DataSource
{
private:
    string filename;
public:
    FileSourceData(string file) : filename(file) 
    {
        
    }

    void writeData(string contents) override
    {
        ofstream ofs(filename);
        ofs << contents;
    }

    string readData() override
    {
        ifstream ifs(filename);
        string line;
        ostringstream oss;

        while (getline(ifs, line))
            oss << line;

        return oss.str();
    }
};

class DataSourceDecorator : public DataSource
{
public:
    DataSourceDecorator(DataSource& ds) : data_source{ds}  
    {

    }

    void writeData(string contents) override
    {
        data_source.writeData(contents);
    }

    string readData() override
    {
        return data_source.readData();
    }

private:
    DataSource& data_source;
};

class CompressDataSource : public DataSourceDecorator
{
public:
    CompressDataSource(DataSource& ds) : DataSourceDecorator{ds}
    {

    }

    void writeData(string contents) override
    {
        contents += "--Data has been compressed";
        DataSourceDecorator::writeData(contents);
    }

    string readData() override
    {

        return DataSourceDecorator::readData() + "--data has been decompressed";
    }

};

class EncryptedDataSource : public DataSourceDecorator
{
public:
    EncryptedDataSource(DataSource& ds) : DataSourceDecorator{ds}
    {

    }

    void writeData(string contents) override
    {
        contents += "--Data has been encrypted";
        DataSourceDecorator::writeData(contents);
    }

    string readData() override
    {

        return DataSourceDecorator::readData() + "--data has been decrypted";
    }

};

int main(int argc, char **argv)
{
    FileSourceData fsd("decorator-data.txt");
    CompressDataSource comp_file_data(fsd);
    EncryptedDataSource enc_file_data(comp_file_data);
    
    enc_file_data.writeData("This is hanoi raw data.");

    auto data = enc_file_data.readData();

    cout << data << endl;
    return 0;
}

