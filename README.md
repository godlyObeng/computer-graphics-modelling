# Computer Graphics Modelling Using OpenGL and C++

# Requirements
* To create a Translucent cube
* A regular tetrahedron inside the cube (All sides must be equal)
* Only use GL_TRIANGLES and glBegin/glEnd
* Vertices must be explicitly defined (glVertex3f)
* Enable face culling

# How I implemented the tasks
I started by following the requirements given and applying them accordingly. Since the tetrahedron is inside the cube, I drew the cube first. When starting with the cube, I did a freehand sketch to see how it will look and following that, I used glBegin/glEnd and GL_TRIANGLES as required to draw each triangle of the cube explicitly. By doing this, not only will it help in making drawing the tetrahedron easy, but it also came out together after getting one side of the cube drawn. I followed along the already defined vertices and continued drawing the remaining faces for the cube. After getting the shape of the cube, I used glColor4f to get the transparency as required by the assignment. At this point, 4 of the requirements for the assignment was completed and it was left with the tetrahedron. Since the vertices for the cube were already defined, I used them to draw the tetrahedron. The main part for this question was to get the cube and after finishing that, using the vertices to draw out the tetrahedron was simple since the cube has equal sides so by following the points, the tetrahedron will also be regular.
But I came across some minor problems where the points of the tetrahedron was always ending up in the middle of the cube instead of the corner. Although this was not wrong, it was not as shown in the assignment sheet, so I got help from Kamil in correcting this issue.
Two methods have been provided in the code on how to rotate the shapes to get a better view.

![image](https://user-images.githubusercontent.com/58789172/123662802-b5ca6400-d82d-11eb-8d6e-a9b822ab81ee.png)
