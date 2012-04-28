/*
 * string.c
 *
 *  Created on: 2012-4-26
 *      Author: hujin
 */
#include "bitmap.h"
#include "strings.h"
/**
 * 判断字符串是否包含子串中的所有字符
 * @param char * str 待搜索的字符串
 * @param char * substr 待搜索的字符列表
 * @return 0 or 1
 */
int string_has_chars_of(string str, string substr) {
	bitmap_t * bitmap = bitmap_new(256, 0);
	int i = 0;
	while(str[i] != '\0') {
		bitmap_set(bitmap, str[i]);
		i ++;
	}

	i = 0;
	while(substr[i] != '\0') {
		if(0 == bitmpa_get(bitmap, substr[i])) {
			bitmap_free(bitmap);
			return 0;
		}
		i ++;
	}
	bitmap_free(bitmap);
	return 1;
}
