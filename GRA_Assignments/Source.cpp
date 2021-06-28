#include <iostream>
#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#define WIDTH               800
#define HEIGHT              800

void init();
void draw_tetrahedron();
void draw_cube();
void display(GLFWwindow* window);

//global cube vertices
float r = 1.0f;
GLfloat vertices[8][3] = {
		{-r, r, r},
		{r, r, r},
		{-r, -r, r},
		{r, -r, r},

		{-r, r, -r},
		{r, r, -r},
		{-r, -r, -r},
		{r, -r, -r},
};

/*The main function that runs everything*/
int main() {
	//GLFW Initialisation
	if (!glfwInit()) {
		std::cout << "GLFW initialisation failed." << std::endl;
		return -1;
	}

	/*Creating the window*/
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "GRA Assignment", NULL, NULL);
	if (!window)
	{
		std::cout << "GLFW failed to create window." << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	init();

	while (!glfwWindowShouldClose(window))
	{
		display(window);
	}
	glfwTerminate();

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		std::cout << "GLEW initialisation failed: "
			<< glewGetErrorString(err) << std::endl;
		return -1;
	}
	return 0;
}

/*Initialises the functions*/
void init() {
	float bkg = 0.5f; //bkg color
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	/*Background colour*/
	glClearColor(bkg, bkg, bkg, bkg);

	/* Enable back-face culling */
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5.f * (GLfloat)WIDTH / (GLfloat)HEIGHT, 5.f * (GLfloat)WIDTH / (GLfloat)HEIGHT, -5.f, 5.f, -5.f, 5.f);

	/* Enable transparency blending */
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

/*Draws the cube*/
void draw_cube() {
	float r = 1.0f; //the vertices for the cube
	float alpha = 0.1f; //Can be used to change the transparency

	glBegin(GL_TRIANGLES);
	//front
	glColor4f(0.0f, 0.0f, 0.0f, alpha);
	glVertex3fv(vertices[0]);
	glVertex3fv(vertices[1]);
	glVertex3fv(vertices[3]);

	glColor4f(0.0f, 0.0f, 0.0f, alpha);
	glVertex3fv(vertices[0]);
	glVertex3fv(vertices[3]);
	glVertex3fv(vertices[2]);

	//right
	glColor4f(0.0f, 0.0f, 0.0f, alpha);
	glVertex3fv(vertices[1]);
	glVertex3fv(vertices[5]);
	glVertex3fv(vertices[7]);

	glColor4f(0.0f, 0.0f, 0.0f, alpha);
	glVertex3fv(vertices[1]);
	glVertex3fv(vertices[7]);
	glVertex3fv(vertices[3]);

	//left
	glColor4f(0.0f, 0.0f, 0.0f, alpha);
	glVertex3fv(vertices[0]);
	glVertex3fv(vertices[6]);
	glVertex3fv(vertices[4]);

	glColor4f(0.0f, 0.0f, 0.0f, alpha);
	glVertex3fv(vertices[0]);
	glVertex3fv(vertices[2]);
	glVertex3fv(vertices[6]);

	//back
	glColor4f(0.0f, 0.0f, 0.0f, alpha);
	glVertex3fv(vertices[4]);
	glVertex3fv(vertices[7]);
	glVertex3fv(vertices[5]);

	glColor4f(0.0f, 0.0f, 0.0f, alpha);
	glVertex3fv(vertices[4]);
	glVertex3fv(vertices[6]);
	glVertex3fv(vertices[7]);

	//top
	glColor4f(0.0f, 0.0f, 0.0f, alpha);
	glVertex3fv(vertices[0]);
	glVertex3fv(vertices[5]);
	glVertex3fv(vertices[1]);

	glColor4f(0.0f, 0.0f, 0.0f, alpha);
	glVertex3fv(vertices[0]);
	glVertex3fv(vertices[4]);
	glVertex3fv(vertices[5]);

	//bottom
	glColor4f(0.0f, 0.0f, 0.0f, alpha);
	glVertex3fv(vertices[2]);
	glVertex3fv(vertices[3]);
	glVertex3fv(vertices[7]);

	glColor4f(0.0f, 0.0f, 0.0f, alpha);
	glVertex3fv(vertices[2]);
	glVertex3fv(vertices[7]);
	glVertex3fv(vertices[6]);

	glEnd();

}

/*Draws the tetrahedron*/
void draw_tetrahedron() {

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3fv(vertices[0]);
	glVertex3fv(vertices[6]);
	glVertex3fv(vertices[3]);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3fv(vertices[0]);
	glVertex3fv(vertices[3]);
	glVertex3fv(vertices[5]);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3fv(vertices[0]);
	glVertex3fv(vertices[5]);
	glVertex3fv(vertices[6]);

	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3fv(vertices[6]);
	glVertex3fv(vertices[5]);
	glVertex3fv(vertices[3]);

	glEnd();
}

/*Prints out the objects onto the display*/
void display(GLFWwindow* window) {

	/* Render here */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/*Rotates the objects*/
	//Rotates it horizontally (To check the acuracy of the tetrahedron)
	//glRotatef(0.05f, 0, 1, 0);
	
	//Rotates it diagonally for overall view
	glRotatef(0.07f, 7.5f, 7.5f, 1.0f);

	/*Draws the shapes*/
	draw_cube();
	draw_tetrahedron();
	
	/*Swap the windows*/
	glfwSwapBuffers(window);
	glfwPollEvents();
}