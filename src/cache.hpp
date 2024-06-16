#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>


uint8_t cur_time = 0; // increment this with every cache access

// Design Cache

struct CacheEntry {
	std::string pathName;  // e.g. "path/to/file.txt" 
	std::ifstream *file;   // ptr to the file in memory	
	uint8_t lastUsed;      // time at which the entry was last accessed
	
};



// note: I need to define an eviction policy --> mayeb start with least recently used


class Cache {
	
	public:
		uint8_t numEntries;
		uint8_t currentSize;
		CacheEntry* cache;                                  // ptr to an array of cache entries
		
		Cache(uint8_t cacheSize);
		std::ifstream* find(std::string pathName);           // returns a file 
		int add(std::string pathName, std::ifstream* file);  // adds an entry to the cache
	private:
		int evict();                     
		
};




Cache::Cache(uint8_t cacheSize) {
	// initializes a cache of cacheSize
	// sets the num entries attribute

	cache = new CacheEntry[cacheSize];  
	numEntries = cacheSize;
	currentSize = 0;
}



int Cache::evict() {
	uint8_t currentLRU = cache[0].lastUsed;
	std::string currentLRUPath = cache[0].pathName;
	// iterate over the cache and locate the entry that has the lowest lastUsed value
	uint8_t index = 0;

	for (index; index < currentSize; index++) {
		CacheEntry entry = cache[index];
		if (entry.lastUsed < currentLRU) {
			currentLRU = entry.lastUsed;
			currentLRUPath = entry.pathName;		
		}
		
	}

	// remove the lru entry from the cache
	cache[index].;
	return 0;
}



int Cache::add(std::string pathName, std::ifstream* file) {

	// create a cache entry
	CacheEntry entry;
	entry.pathName = pathName;
	entry.file = file;
	entry.lastUsed = cur_time;
	
	// add to the cache
	if (currentSize < numEntries) {
		
		cur_time ++;
		return 0;
	} else {
		// evict lru entry from the cache
		evict();
	}

	cur_time++;
	return 0;
}


std::fstream* Cache::find(std::string pathName) {
	
	// returns a ptr to a file if in the cache
	
	

}
