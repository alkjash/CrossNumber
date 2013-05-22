#include <cstdio>
#include <cassert>
#include "IM.h"

/* Basic API for Indexed multiset class */

using namespace std;

void IM::set_group(int n) {
	if (n >= GROUP_MAX || n < 0) {
		printf("IM::set_group: invalid input!\n");
		return;
	}
	group_size = n;
}

void IM::add(int n) {
	if (n >= group_size || n < 0) {
		printf("IM::add: invalid input, not added!\n");
		return;
	}
	values[n]++;
}

void IM::remove(int n) {
	if (n >= group_size || n < 0) {
		printf("IM::remove: invalid input, not removed!\n");
		return;
	} else if (values[n] <= 0) {
		printf("IM::remove: number doesn't lie in set!\n");
		return;
	}
	values[n]--;
}

static
int gcd(int m, int n) {
	if (m == 0) {
		return n;
	} else if (n == 0) {
		return m;
	}

	if (m > n) {
		return gcd((m % n), n);
	} else {
		return gcd(m, (n % m));
	}
}

/* Helper which computes order of m with respect to C_n, 0 <= m < n */
static
int order(int m, int n) {
	cassert(gcd(m,n) > 0);
	cassert((n % gcd(m,n)) == 0);
	return (n / (gcd(m, n)));
}

/* Computes cross number invariant of IM */
int IM::cross_num(void) {
	int ret = 0;

	for (int i = 0; i < group_size; i++) {
		ret += values[i] * order(i, group_size);
	}

	return ret;
}
