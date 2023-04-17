//读取二进制文件
	fstream file;
	file.open("/home/sTest/data/search_engine/ExpIndex", ios::binary|ios::in);//此处文件路径为arm平台的路径
	if (!file.is_open()) {
		cout << "No file";
		return 0;

	}
	cout<<"infile"<<endl;
	vector<index> idx;//存在idx里
	for (int i=0; i <2000; i++) {
		index temp;
		file.read((char*)&temp.len, sizeof(temp.len));
		for (int j = 0; j < (temp.len); j++)
		{
			unsigned int binary_temp;
			file.read((char*)&binary_temp, sizeof(binary_temp));
			temp.arr.push_back(binary_temp);
		}
		idx.push_back(temp);
	}
	file.close();
	/*---------------------------------------------------------------------------------------------------------*/
	file.open("/home/sTest/data/search_engine/ExpQuery",  ios::in);
	if (!file.is_open()) {
		cout << "No file";
		return 0;

	}
	cout<<"infile"<<endl;
	int query[1000][5]={0};//放在query数组中
	string line;
	int count = 0;
	while (getline(file, line)) {
		stringstream ss; //输入流
		ss << line; //向流中传值
		int a = 0;
		while (!ss.eof()) {
			int temp;
			ss >> temp;
			query[count][a] = temp;
			a++;
		}
		count++;
	}
