#ifndef DBSystem_H
#define DBSystem_H
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>

using namespace std;
typedef long long int LL;

class Page
{
    private:
        //meta info of the table
        string tablename;
        LL start_index;
        LL end_index;

        //vector of the records.
        vector< vector < string > > records;

    public:
        //Using default constructor to initialize the page.
        // Use generate_page
        
        //modify the info of the page after creation of page.
        void generate_page(string arg_tablename, LL arg_start_index, LL arg_end_index)
        {
            // Clears any existing data and updates internal structures according
            // to the new page.

            tablename = arg_tablename;
            start_index = arg_start_index;
            end_index = arg_end_index;
        }

        //will read the given file.
        //will return 1 on success and 0 othereise.
        bool read_page_file(string path_to_pagefile)
        {
        }

        //will write to page_file.
        //will return 1 on success and 0 othereise.
        bool write_page_file(string path_to_pagefile)
        {
        }

        //will return the entire record in a vector.
        vector<string> get_record(LL record_id)
        {
        }

        //will return -1 on failure. Else index where new record is stored.
        LL insert_record(vector<string>)
        {
        }
};

class DBSystem
{
    private:
        LL page_size;
        LL num_pages;
        string path;
        vector < string > tables;
        map < string, vector < pair < string, string > > > attributes;
        
        vector< vector<string> > ParseCSV(string csvFilePath);
        // Struct for page info
        struct page_info{
            string tablename;
            string page_file_path;
            int start_record_id;
            int end_record_id;
            int LRU;
        };

        Page* MainMemory;

    public:
        DBSystem();
        void readConfig(string str);
        void populateDBInfo();
        string getRecord(string tableName, int recordId);
        void insertRecord(string tableName, string record);
};

#endif

