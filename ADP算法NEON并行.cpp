class index {
public:
	int len = 0;
	vector<unsigned int> arr;
};

bool operator<(const index& s1, const index& s2)
{
	return s1.len < s2.len; 
}
index s;
index temp;

vector<unsigned int>& ADP_NEON(int* list, vector<index>& idx, int num)
{
	vector<unsigned int> S;
	int s = 1;
	bool found = true;
	vector<index> idx_;
	for (int i = 0; i < num; i++)
	{
		idx_.push_back(idx[list[i]]);
	}
	sort(idx_.begin(), idx_.end());
	/*for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < idx_[i].len; j++)
		{
			cout << idx_[i].arr[j] << " ";
		}
		cout << endl;
	}*/
	for (int t = 0; t < idx_[0].len; t++)
	{
		unsigned int e = idx_[0].arr[t];
		uint32x4_t e_ = vmovq_n_u32(e);
		while (s != num && found == true)
		{
			uint32_t length = ceil(idx_[s].len / 4) * 4;
			for (int m = idx_[s].len; m < length; m++)
				idx_[s].arr[m] = 0;
			for (int i = 0; i < idx_[s].len; i+=4)
			{
				unsigned int res[4] = { 0 };
				uint32x4_t temp1 = vld1q_u32(&idx_[s].arr[i]);
				uint32x4_t result = vceqq_u32(e_, temp1);
				vst1q_u32(res, result);
				found = false;
				if (res[0] == 1 || res[1] == 1 || res[2] == 1 || res[3] == 1)
				{
					found = true;
					break;
				}
			}
			s = s + 1;
		}
		if (s == num && found == true)
			S.push_back(e);
	}
	for (int i = 0; i < S.size(); i++)
		cout << S.at(i) << endl;
	return S;
}
