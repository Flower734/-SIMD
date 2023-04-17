vector<unsigned int>& ADP_P_AVX(int* list, vector<index>& idx, int num)
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
		__m256i qwq;
		qwq = _mm256_set1_epi32(e);
		while (s != num && found == true)
		{
			for (int i = 0; i < idx_[s].len; i++)
			{
				found = false;
				__m256i ewe, result;
				ewe = _mm256_set_epi32(idx_[s].arr[i], idx_[s].arr[i + 1], idx_[s].arr[i + 2], idx_[s].arr[i + 3], idx_[s].arr[i + 4], idx_[s].arr[i + 5], idx_[s].arr[i + 6], idx_[s].arr[i + 7]);
				result = _mm256_set1_epi32(0);
				result = _mm256_sub_epi32(ewe, qwq);
				unsigned int res[8] = { 0 };
				_mm256_storeu_epi32(res, result);
				for (int i = 0; i < 8; i++) {
					if (res[i] == 0) {
						found = true;
						break;
					}
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
