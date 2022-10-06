class TimeMap {
    unordered_map<string, unordered_map<int, string>> keyMap;

public:
	TimeMap() {}

	void set(string key, string value, int timestamp) {
		keyMap[key][timestamp] = value;
	}

	string get(string key, int timestamp) {
		if (keyMap.find(key) == keyMap.end()) return "";

		for (int i = timestamp; i >= 0; --i)
			if (keyMap[key].find(i) != keyMap[key].end()) return keyMap[key][i];
	
        return "";
    }	
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */