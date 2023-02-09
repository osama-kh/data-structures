#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS


typedef struct StudentNode {//the student struct

	int ID;
	int mid_term_grade;
	int Exam_grade;
	 StudentNode* left;
	 StudentNode* right;
	 StudentNode* parent;

}StudentNode;

typedef struct BST {// Binary searching tree struct

	StudentNode* root;

}BST;



StudentNode* contain(BST* tree, int ID) {// help function : search on student by his ID
	if (tree->root->ID == ID)
		return tree->root;
	else
		return contain(tree->root->left, ID) || contain(tree->root->right,ID);


}


void insert(BST* tree, int ID) {// join a new student

	StudentNode* node = tree->root;
	if (contain(tree, ID)->ID == ID);
	else {
		StudentNode* new_student=(StudentNode*)malloc(sizeof(StudentNode));
		new_student->ID = ID;
		new_student->Exam_grade = 0;
		new_student->mid_term_grade = 0;
		new_student->left = NULL;
		new_student->right = NULL;
		new_student->parent = NULL;

		StudentNode* help = NULL;
		StudentNode* defaulte = tree->root;

		while (defaulte != NULL) {
			help = defaulte;
			if (new_student->ID < defaulte->ID)
				defaulte = defaulte->left;
			else
				defaulte = defaulte->right;
		}

		new_student->parent = help;
		if (help == NULL) 
		{
			tree->root = new_student;
		}

		else if (help->ID > ID)
		{
			help->left = new_student;
		}
		else
		{
			help->right = new_student;
		}
	}
}


void updateMidtermgrade(BST* tree, int ID, int newGrade) {// to update te medterm grade
	contain(tree, ID)->mid_term_grade=newGrade;

}

void updateExamGrade(BST* tree, int ID, int newGrade) {// to update the Exam grade

	contain(tree, ID)->Exam_grade = newGrade;
}

int getFinalGrade(BST* tree, int ID) {// calculate the final grade

	float finalgrade =(contain(tree, ID)->mid_term_grade*(30/100))+
	(contain(tree, ID)->Exam_grade*(70/100));

	int help = finalgrade;
	float mG = help + 0.5;
	if (mG <= finalgrade)
		return mG + 0.5;
	else {
		return mG - 0.5;
	}
}

int countstudents(BST* tree) {// to count the number of students
	int count = 0;
	if (tree->root == NULL) {
		return 0;
	}

	else {
		count = 1;
		return count + countstudents(tree->root->left) + countstudents(tree->root->right);
	}

}

int sum_of_finalGrades(BST* tree) {// to get the sum of all the final grades

	int sum = 0;

	if (tree->root == NULL) {
		return 0;
	}
	else {
		sum +=getFinalGrade(tree,tree->root->ID);
		return sum + sum_of_finalGrades(tree->root->left) + sum_of_finalGrades(tree->root->right);

	}

}

double getAverageGrade(BST* tree) {// calculate the average of the final grade

	return sum_of_finalGrades(tree) / countstudents(tree);
}





void reportGrade(BST* tree) {// to print a report in id order that have all the grades of the students

	if (tree->root != NULL) {

		if (tree->root->left != NULL) {


			reportGrade(tree->root->left);
		}
		
		printf("ID    midterm grade    Grade of Exam     final grade \n");
		printf("%d        %d             %d                %d  \n", tree->root->ID, tree->root->mid_term_grade, tree->root->Exam_grade, getFinalGrade(tree,tree->root->ID));

		if (tree->root->right != NULL) {
			reportGrade(tree->root->right);
		}
	}
	else {


		printf("there are no students!\n ");
	}

}






int getNumOfFails(BST* tree) {//number of students fails

	int count = 0;
	if (tree->root == NULL) {
		return 0;
	}

	if(getFinalGrade(tree,tree->root->ID) < 56){
		count = getFinalGrade(tree, tree->root->ID);
}

	else {
				return count + countstudents(tree->root->left) + countstudents(tree->root->right);
	}

}

int getNumOfgood(BST* tree) {// get the number of students with good grade

	int count = 0;
	if (tree->root == NULL) {
		return 0;
	}

	if (getFinalGrade(tree, tree->root->ID) >= 56 && getFinalGrade(tree, tree->root->ID) <= 75) {
		count = getFinalGrade(tree, tree->root->ID);
	}

	else {
		return count + countstudents(tree->root->left) + countstudents(tree->root->right);
	}

}


int getNumOfverygood(BST* tree) {// get the number of students with very good grade

	int count = 0;
	if (tree->root == NULL) {
		return 0;
	}

	if (getFinalGrade(tree, tree->root->ID) >= 76 && getFinalGrade(tree, tree->root->ID) <= 94) {
		count = getFinalGrade(tree, tree->root->ID);
	}

	else {
		return count + countstudents(tree->root->left) + countstudents(tree->root->right);
	}

}


int getNumOfExcellent(BST* tree) {// get the number of students with Excellent grade

	int count = 0;
	if (tree->root == NULL) {
		return 0;
	}

	if (getFinalGrade(tree, tree->root->ID) >= 95 && getFinalGrade(tree, tree->root->ID) <= 100) {
		count = getFinalGrade(tree, tree->root->ID);
	}

	else {
		return count + countstudents(tree->root->left) + countstudents(tree->root->right);
	}

}





void ReportStatistics(BST* tree) {//to print the Exam Statistics

	printf("            Grade     final grade \n");
	printf("Good       (56-75) \t  %d\n",getNumOfgood(tree));
	printf("very Good  (76-94) \t  %d\n",getNumOfverygood(tree));
	printf("Exellent   (95-100)\t  %d\n",getNumOfExllent(tree));
}








