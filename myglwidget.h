#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class MyGLWidget : public QOpenGLWidget
{
public:
  MyGLWidget(QWidget *parent) : QOpenGLWidget(parent) { }
  GLuint vertex_buffer;
  GLuint program;
protected:
  void initializeGL()
  {
      QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
      f->glClearColor(0.2, 0.3, 0.4, 1.0);

      GLuint vertex_shader = f->glCreateShader(GL_VERTEX_SHADER);
      GLuint fragment_shader = f->glCreateShader(GL_FRAGMENT_SHADER);
      static const char vertex_shader_src[] = "#version 300 es\nlayout(location = 0) in vec3 vertexPosition_modelspace;\nvoid main(){\ngl_Position.xyz = vertexPosition_modelspace;\ngl_Position.w = 1.0;\n}\n";
      static const char fragment_shader_src[] = "#version 300 es\nout mediump vec3 color;\nvoid main(){\ncolor = vec3(1,0,0);\n}\n";
      static const char *vertex_shader_src_ptr = vertex_shader_src;
      static const char *fragment_shader_src_ptr = fragment_shader_src;
      f->glShaderSource(vertex_shader, 1, &vertex_shader_src_ptr, NULL);
      f->glCompileShader(vertex_shader);
      {
          GLint len;
          f->glGetShaderiv(vertex_shader, GL_INFO_LOG_LENGTH, &len);
          char log[len];
          f->glGetShaderInfoLog(vertex_shader, len, NULL, log);
      }
      f->glShaderSource(fragment_shader, 1, &fragment_shader_src_ptr, NULL);
      f->glCompileShader(fragment_shader);
      {
          GLint len;
          f->glGetShaderiv(fragment_shader, GL_INFO_LOG_LENGTH, &len);
          char log[len];
          f->glGetShaderInfoLog(fragment_shader, len, NULL, log);
      }
      program = f->glCreateProgram();
      f->glAttachShader(program, vertex_shader);
      f->glAttachShader(program, fragment_shader);
      f->glLinkProgram(program);
      {
          GLint len;
          f->glGetProgramiv(program, GL_INFO_LOG_LENGTH, &len);
          char log[len];
          f->glGetProgramInfoLog(program, len, NULL, log);
      }
      f->glDeleteShader(vertex_shader);
      f->glDeleteShader(fragment_shader);

      static const GLfloat vertex_buffer_data[] = {
          0.0, 0.8, 0.0,
          -0.8, -0.8, 0.0,
          0.8, -0.8, 0.0
      };
      f->glGenBuffers(1, &vertex_buffer);
      f->glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
      f->glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data), vertex_buffer_data, GL_STATIC_DRAW);
  }
  void resizeGL(int w, int h)
  {
      QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
      f->glViewport(0, 0, w, h);
  }
  void paintGL()
  {
      QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
      f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      f->glEnableVertexAttribArray(0);
      f->glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
      f->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
      f->glDrawArrays(GL_TRIANGLES, 0, 3);
      f->glDisableVertexAttribArray(0);
  }
};
#endif // MYGLWIDGET_H
