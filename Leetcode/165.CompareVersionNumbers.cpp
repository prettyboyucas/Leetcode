
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int ret = 0;
        
        //将string转成C风格字符数组
        char* vStr1 = (char*) version1.c_str();
        char* vStr2 = (char*) version2.c_str();
        
        while(ret == 0 && (*vStr1 != '\0' || *vStr2 != '\0'))
        {
            //strtol将会扫描参数nptr字符串，跳过前面的空格字符，直到遇上数字或正负符号才开始做转换，再遇到非数字或字符串结束时('\0')结束转换，并将结果返回。第二个参数是一个传出参数，函数返回时指向后面未被识别的第一个字符，即‘.’
            long v1 = *vStr1 == '\0' ? 0 : strtol(vStr1, &vStr1, 10);
            long v2 = *vStr2 == '\0' ? 0 : strtol(vStr2, &vStr2, 10);
            if(v1 > v2)
                ret = 1;
            else if(v1 < v2)
                ret = -1;
            else
            {
                if(*vStr1 != '\0') vStr1++;
                if(*vStr2 != '\0') vStr2++;
            }
        }
        
        return ret;
        
    }
};


class Solution {  
private:  
        vector<int> v1,v2;  
public:  
    //split the string by '.'   
    void split_string(const char *str , vector<int> &v)     
    {  
        char *buf = new char[ strlen(str) + 1 ];  
        strcpy(buf,str);  
        char *p = strtok(buf,".");  
        while( p!=NULL )  
        {  
            v.push_back( atoi(p) ) ;  
            p = strtok(NULL,".");  
        }  
    }  
      
    //compare two version  
    int compareVersion(string version1, string version2)   
    {  
        const char *str1 = version1.c_str();  
        const char *str2 = version2.c_str();  
          
        split_string(str1,v1);  
        split_string(str2,v2);  
          
        return judge();  
    }  
      
    int judge()  
    {  
        //prune the suffix zero : 1.0 == 1  
        while( v1.size()!=0 && v1[v1.size()-1]==0 )  
        {  
            v1.pop_back();         
        }  
         while( v2.size()!=0 && v2[v2.size()-1]==0 )  
        {  
            v2.pop_back();         
        }  
          
        int size = min( v1.size(),v2.size() );  
        int i;  
        for(i=0;i<size;i++)  
        {  
            if( v1[i]>v2[i] )   return 1;  
            else if( v1[i]<v2[i] ) return -1;  
            else continue;  
        }  
          
        if( v1.size() > v2.size() )       
        {   
              return 1;    
        }  
        else if( v1.size() < v2.size() ) return -1;  
        else return 0;  
          
    }  
};  



//the same as solution 1

class Solution {
public:
	int compareVersion(string version1, string version2) {

		int res = 0;
		char* ptr1 = const_cast<char*>(version1.c_str());
		char* ptr2 = const_cast<char*>(version2.c_str());

		while (*ptr1 != '\0' || *ptr2 != '\0') {
			long v1 = (*ptr1 == '\0') ? 0 : strtol(ptr1, &ptr1, 10);
			long v2 = (*ptr2 == '\0') ? 0 : strtol(ptr2, &ptr2, 10);

			if (v1 > v2)
				return 1;
			else if (v1 < v2)
				return -1;
			else {
				if (*ptr1 != '\0')
					ptr1++;
				if (*ptr2 != '\0')
					ptr2++;
			}
		}
		return 0;
	}
};


class Solution {
public:
	int compareVersion(string version1, string version2) {

		//if (version1.empty() || version2.empty())
		//	return 0;
		vector<long> v1, v2;

		const char* str1 = version1.c_str();
		const char* str2 = version2.c_str();

		split_version1(str1, v1);
		split_version1(str2, v2);

		for (int i = 0; i < v1.size() || i < v2.size(); i++) {

			int ver1 = (i < v1.size()) ? v1[i] : 0;
			int ver2 = (i < v2.size()) ? v2[i] : 0;
			if (ver1 > ver2)
				return 1;
			else if (ver2 > ver1)
				return -1;
		}
		return 0;



	}
private:
	void split_version(const char*str, vector<int>& v) {
		//char * strtok ( char * str, const char * delimiters );
		char *buf = new char[strlen(str) + 1];
		//char *bur = (char*) malloc(size(char)*(strlen(str)+1));
		strcpy(buf, str);
		char* p = strtok(buf, ".");
		while (p != nullptr) {
			v.push_back(atoi(p));
			p = strtok(nullptr, ".");
		}
		//delete buf;
		//buf = nullptr;
	}
	void split_version1(const char* str, vector<long> v) {
		char* buf = new char[strlen(str) + 1];
		strcpy(buf, str);
		while (*buf != '\0') {
			long temp = strtol(buf, &buf, 10);
			v.push_back(temp);
			if (*buf != '\0')
				buf++;
		}
		delete buf;
		buf = nullptr;
	}
};
