vector<unsigned int>& ADP_P_SSE(int* list, vector<index>& idx, int num)
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
		__m128i qwq;
		qwq = _mm_set1_epi32(e);
		while (s != num && found == true)
		{
			for (int i = 0; i < idx_[s].len; i+=4)
			{
				found = false;
				__m128i ewe, result;
				ewe = _mm_loadu_epi32(&idx_[s].arr[i]);
				result = _mm_set1_epi32(0);
				result = _mm_sub_epi32(ewe, qwq);
				int res[4] = { 0 };
				_mm_storeu_si64(&res[0], result);
				_mm_storeu_si64(&res[2], result);
				for (int i = 0; i < 4; i++) {
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
	
	return S;
}
