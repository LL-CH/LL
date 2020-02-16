int compress(char *chars, int charsSize)
{
	if (charsSize<2)
		return charsSize;

	char tmp;
	int index1, index2;
	int newSize = charsSize;
	for (int i = 0; i < newSize;) {
		tmp = chars[i];
		index1 = i;
		int count = 0;
		int ccount = 0;
		while ((index1 < newSize) && (tmp == chars[index1])) {
			count++;
			index1++;
		}
		if (count > 1) {
			index2 = index1;
			while (count) {
				chars[--index2] = count % 10 + '0';
				count = count / 10;
				ccount++;
			}
			index2 = index1;
			for (int j = i + ccount; j > i; j--) {
				chars[j] = chars[--index2];
			}
			index2 = index1;
			if (index2 < newSize) {
				for (int k = i + ccount + 1; index2 < newSize; k++) {
					chars[k] = chars[index2++];
				}
			}
			index2 = index1;
			newSize = newSize - (index2 - 1 - ccount - i);
			i = i + ccount + 1;
		}
		else
			i = i + 1;
	}
	return newSize;
}