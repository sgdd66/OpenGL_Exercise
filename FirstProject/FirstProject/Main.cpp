#include<glad\glad.h>
#include<GLFW\glfw3.h>
#include<iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
int main(){
	
	/*Ϊ��ʹopenGL����Ӧ���ڲ�ͬ��OS�У��Դ��ڵĹ����Լ���OS�Ľ����ͱ�����������
	GLFW����ΪopenGL�ṩ����OS�����Ŀ⣬�����ṩ���ڣ���Ӧ��������ȹ���*/
	//glfw������ʼ��
	glfwInit();
	//����glfw��֧�ֵ����汾�ʹΰ汾��Ӧ�ú���ģʽ��������openGL������汾Ҫ��ʱ�Ͳ���ִ�У��������
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//����һ������
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	//openGLֻ��һ�ֱ�д�淶����ͬ���Կ����һ��߸��˶����Ա�дopenGl�ľ���ʵ��
	//����ʵ��ʹ��openGL�ĺ�����Ҫ�����Կ��������汾��ͬ�����ġ�Ϊ�˱����α�д��
	//����ʹ��GLAD��GLAD�ڱ���ʱ��ȥѰ����غ�����λ�á���������Ҫ����Glad�Ļ���
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//����һ���ӿڣ��ӿڿ����ڴ��ڵĲ�ͬλ��
	glViewport(0, 0, 800, 600);

	//������ڸı䣬�ӿ�Ӧ��Ҳ�����仯���������ڱ仯ʱ�Ļص�����
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//ѭ���ȴ��¼���Ӧ
	while(!glfwWindowShouldClose(window))
	{
		//����������
		processInput(window);

		/*******��Ⱦָ��*******/

		//����������Ӵ�����ɫ
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		//�����ɫ�����������趨�������ɫ���������
		glClear(GL_COLOR_BUFFER_BIT);

		/*���ֱ������ʾ���Ļ��������ƻ�����˸Ч����һ���ں󻺳������ƣ�Ȼ��ֱ�ӽ�������������ֵ����*/
		//����ǰ�󻺳�
		glfwSwapBuffers(window);
		//����Ƿ����¼����������е��ûص�����
		glfwPollEvents();    
	}

	//������Դ
	glfwTerminate();
    return 0;


}

//���ڱ仯�Ļص�����
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

//��ֵ��Ӧ�Ļص�����
void processInput(GLFWwindow *window)
{
	//�����Esc�������£����ڹر�
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}