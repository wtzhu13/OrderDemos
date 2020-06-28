"""
DATE: 202006
E-MAIL: wtzhu_13@163.com

AUTHOR: Fred
VERSION:
    更多项目内容关注：https://blog.csdn.net/wtzhu_13
"""

# 读取mnist数据集
from tensorflow.examples.tutorials.mnist import input_data
import tensorflow as tf


mnist = input_data.read_data_sets("MNITS_data/", one_hot=True)  # 这里one_hot为True其实就是说每一条数据对应的标签是一个向量
sess = tf.InteractiveSession()  # 创建session


# 函数声明部分
def weight_variable(shape):
    initial = tf.truncated_normal(shape,stddev=0.1)
    return tf.Variable(initial)


def bias_variable(shape):
    initial = tf.constant(0.1,shape=shape)
    return tf.Variable(initial)


# tf.nn.conv2d中输入x的shape是[batch, in_height, in_width, in_channels]，滤波器的shape是[filter_height, filter_width, in_channels, out_channels]，strides的shape是[batch, #in_height, in_width, in_channels]，其中strides[0]=strides[3]=1.
def conv2d(x,w):
    return tf.nn.conv2d(x,w,strides=[1,1,1,1],padding='SAME')


# ksize的每一维数值是与输入的每一维相匹配的
def max_pool_2x2(x):
    return tf.nn.max_pool(x,ksize=[1,2,2,1],strides=[1,2,2,1],padding='SAME')


# 占位操作，定义输入输出、dropout操作的丢弃率的数据类型
xs = tf.placeholder(tf.float32,[None,28*28])
ys = tf.placeholder(tf.float32,[None,10])
keep_prob = tf.placeholder(tf.float32)
# 输入
x_image = tf.reshape(xs,[-1,28,28,1])
# 第一层卷积层
w_conv1 = weight_variable([5,5,1,32])
b_conv1 = bias_variable([32])
h_conv1 = tf.nn.relu(conv2d(x_image,w_conv1)+b_conv1)
h_pool1 = max_pool_2x2(h_conv1)
print(h_pool1)
# 第二层卷积层
w_conv2 = weight_variable([5,5,32,64])
b_conv2 = bias_variable([64])
h_conv2 = tf.nn.relu(conv2d(h_pool1,w_conv2)+b_conv2)
h_pool2 = max_pool_2x2(h_conv2)
print(h_pool2)
#平坦化
flat = tf.reshape(h_pool2,[-1,3136])
# 第三层全连接层
w_fc1 = weight_variable([3136,1024])
b_fc1 = bias_variable([1024])
h_fc1 = tf.nn.relu(tf.matmul(flat,w_fc1)+b_fc1)
print(h_fc1)
# Dropout操作
keep_prob = tf.placeholder(tf.float32)
h_fc1_drop = tf.nn.dropout(h_fc1,keep_prob)
# 第四层输出层，使用多分类器softmax
w_fc2 = weight_variable([1024,10])
b_fc2 = bias_variable([10])
y_conv = tf.nn.softmax(tf.matmul(h_fc1_drop,w_fc2)+b_fc2)
print(y_conv)
# 定义损失cross_entropy = -tf.reduce_sum(ys*tf.log(y_conv))
cross_entropy = tf.reduce_mean(-tf.reduce_sum(ys*tf.log(y_conv),reduction_indices=[1]))
# 优化
train_step = tf.train.GradientDescentOptimizer(0.0001).minimize(cross_entropy)
# 精确度
correct_prediction = tf.equal(tf.argmax(y_conv,1), tf.argmax(ys,1))  # tf.equal返回值true或falae
accuracy = tf.reduce_mean(tf.cast(correct_prediction,tf.float32))
# 初始化全部变量
tf.global_variables_initializer().run()
# 迭代训练
for i in range (20000):
    batch = mnist.train.next_batch(50)
    train_step.run(feed_dict={xs:batch[0],ys:batch[1],keep_prob:0.5})
    # 训练迭代美每100次就用训练数据打印输出精确度，使用训练集数据检测一下模型的训练效果
    if i%100 == 0:
        train_accuracy = accuracy.eval(feed_dict={xs:batch[0],ys:batch[1],keep_prob:1.0})
        print("step %d,training accuracy %g"%(i,train_accuracy))
# 测试，使用测试数据检测模型的效果，打印输出精确度
print("test accuracy %g"%accuracy.eval(feed_dict={xs: mnist.test.images,ys:mnist.test.labels,keep_prob:1.0}))