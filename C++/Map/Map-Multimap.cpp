#include <iostream>
#include <map>

using std::cout;
using std::pair;
using std::map; 	// Collection of key-value pairs, sorted by keys, keys are unique (class template)
using std::multimap; 	// Collection of key-value pairs, sorted by keys (class template)

int main(int argc, char **argv)
{
	pair<char,int> p;
	map<char,int> m;
	multimap<char,int> mm;
	
	cout<<"insert a,b,c,d characters into a map and multimap, with their ascii numerical representations as key-value pairs\n\n";
	char ch;
	for(ch = 'a'; ch <= 'd'; ch++)
	{
		p.first = ch; 
		p.second = (int)ch;
		m.insert(p);
		mm.insert(p);
	}
	
	map<char,int>::iterator it;
	multimap<char,int>::iterator itm;
	
	cout<<"map:\n";
	for(it = m.begin();it != m.end(); it++)
		cout<<(*it).first<<'\t'<<(*it).second<<'\n';
	cout<<"\n\n";
	
	cout<<"multimap:\n";
	for(itm = mm.begin();itm != mm.end(); itm++)
		cout<<(*itm).first<<'\t'<<(*itm).second<<'\n';
	cout<<"\n\n";
		
	pair<map<char,int>::iterator,bool> ret;
	
	cout<<"insert '~' into map\n";
	ch = '~';
	ret = m.insert(pair<char,int>(ch, int(ch)) );
	if(ret.second == false)
	{
		cout <<"line "<<__LINE__<< "element '~' already existed in map";
    		cout << " with a value of " << ret.first->second << '\n';
  	}
	
	cout<<"map:\n";
	for(it = m.begin();it != m.end(); it++)
		cout<<(*it).first<<'\t'<<(*it).second<<'\n';
	cout<<"\n\n";
	
	cout<<"insert '~' into multimap\n";
	itm = mm.insert(pair<char,int>(ch, int(ch)) );
	if(itm == mm.end())
	{
		cout <<"line "<<__LINE__<<" error on insertion on multimap\n";
  	}
	
	cout<<"multimap:\n";
	for(itm = mm.begin();itm != mm.end(); itm++)
		cout<<(*itm).first<<'\t'<<(*itm).second<<'\n';
	cout<<"\n\n";
	
	cout<<"insert 'x' into map\n";
	ch = 'x';
	ret = m.insert(pair<char,int>(ch, int(ch)) );
	if(ret.second == false)
	{
		cout << "line "<<__LINE__<<": element 'x' already existed";
    		cout << " with a value of " << ret.first->second << " in map\n";
  	}
	
	cout<<"map:\n";
	for(it = m.begin();it != m.end(); it++)
		cout<<(*it).first<<'\t'<<(*it).second<<'\n';
	cout<<"\n\n";
	
	cout<<"insert 'x' into multimap\n";
	itm = mm.insert(pair<char,int>(ch, int(ch)) );
	if(itm == mm.end())
	{
		cout <<"line "<<__LINE__<< ": error on insertion on multimap\n";
  	}
	
	cout<<"multimap:\n";
	for(itm = mm.begin();itm != mm.end(); itm++)
		cout<<(*itm).first<<'\t'<<(*itm).second<<'\n';
	cout<<"\n\n";
	
	cout<<"insert 'x' into map again\n";
	ret = m.insert(pair<char,int>(ch, (int)ch) );
	if(ret.second == false)
	{
		cout << "line "<<__LINE__<<": element 'x' already existed";
   		 cout << " with a value of " << ret.first->second << " in map\n";
  	}
	
	cout<<"map:\n";
	for(it = m.begin();it != m.end(); it++)
		cout<<(*it).first<<'\t'<<(*it).second<<'\n';
	cout<<"\n\n";
	
	cout<<"insert 'x' into multimap again\n";
	itm = mm.insert(pair<char,int>('x', (int)ch) );
	if(itm == mm.end())
	{
		cout << "Error on insertion on multimap\n";
  	}
	
	cout<<"multimap:\n";
	for(itm = mm.begin();itm != mm.end(); itm++)
		cout<<(*itm).first<<'\t'<<(*itm).second<<'\n';
	cout<<"\n\n";
	
	cout<<"Find value of 'x' in map\n";
	
	it = m.find('x');
	cout<<(*it).second<<"\n\n";
	
	cout<<"Find value of '~' in multimap\n";
	itm = mm.find('~');
	cout<<(*itm).second<<"\n\n";
	
	return 0;
}