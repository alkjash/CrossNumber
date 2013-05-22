#ifndef _IM_H_
#define _IM_H_

/* Maximum size of a group */
#define GROUP_MAX 1024

/* Class prototype for indexed multiset */
class IM {
		int values[GROUP_MAX];
		int group_size;
	public:
		void set_group (int); // Set underlying group to C_n
		void add (int); // Adds one copy of given int
		void remove (int); // Removes one copy of given int
		int cross_num (void);
};


#endif /* _IM_H_ */
