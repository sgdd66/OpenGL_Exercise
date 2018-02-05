#include<glad\glad.h>
#include<GLFW\glfw3.h>
#include<iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
int main(){
	
	/*为了使openGL可以应用在不同的OS中，对窗口的管理以及与OS的交互就被独立出来。
	GLFW就是为openGL提供的与OS交互的库，可以提供窗口，响应输入输出等功能*/
	//glfw环境初始化
	glfwInit();
	//声明glfw所支持的主版本和次版本，应用核心模式。这样在openGL不满足版本要求时就不能执行，避免出错
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//创建一个窗口
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	//openGL只是一种编写规范，不同的显卡厂家或者个人都可以编写openGl的具体实现
	//所以实际使用openGL的函数就要根据显卡和驱动版本不同而更改。为了避免多次编写，
	//我们使用GLAD。GLAD在编译时会去寻找相关函数的位置。所以这里要加载Glad的环境
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//创建一个视口，视口可以在窗口的不同位置
	glViewport(0, 0, 800, 600);

	//如果窗口改变，视口应该也作出变化，声明窗口变化时的回调函数
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//循环等待事件响应
	while(!glfwWindowShouldClose(window))
	{
		//处理按键输入
		processInput(window);

		/*******渲染指令*******/

		//设置清除后视窗的颜色
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		//清除颜色缓冲区，用设定的清除颜色来填充区域
		glClear(GL_COLOR_BUFFER_BIT);

		/*如果直接在显示器的缓冲区绘制会有闪烁效果，一般在后缓冲区绘制，然后直接将两个缓冲区的值调换*/
		//交换前后缓冲
		glfwSwapBuffers(window);
		//检查是否有事件触发，若有调用回调函数
		glfwPollEvents();    
	}

	//回收资源
	glfwTerminate();
    return 0;


}

//窗口变化的回调函数
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

//键值响应的回调函数
void processInput(GLFWwindow *window)
{
	//如果“Esc”被按下，窗口关闭
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}