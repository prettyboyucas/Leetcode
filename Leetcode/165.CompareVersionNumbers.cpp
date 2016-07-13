
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int ret = 0;
        
        //��stringת��C����ַ�����
        char* vStr1 = (char*) version1.c_str();
        char* vStr2 = (char*) version2.c_str();
        
        while(ret == 0 && (*vStr1 != '\0' || *vStr2 != '\0'))
        {
            //strtol����ɨ�����nptr�ַ���������ǰ��Ŀո��ַ���ֱ���������ֻ��������Ųſ�ʼ��ת���������������ֻ��ַ�������ʱ('\0')����ת��������������ء��ڶ���������һ��������������������ʱָ�����δ��ʶ��ĵ�һ���ַ�������.��
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
