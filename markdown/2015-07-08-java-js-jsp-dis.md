---
layout: post
title: java、js、javascript、jsp的区别
date: 2015-07-08 17:00:01
categories: java
excerpt: java、js、javascript、jsp的区别
---

* content
{:toc}
 
## javascript==js

js是一种脚本语言，在html中，css管理位置，html主管内容，而js主管动作，减轻后台的操作，可以很简单的就实现对输入的数据的验证。比如说注册的时候，用js中的ajax到后台实时验证本用户名是否已经被注册，验证码是否正确或者用来实现异步更新，为用户带来更好的体验。用jquery来验证密码的合法性，输入密码与确认密码是否一样,从而反馈到html页面上，可以通过操控css或者html页面内容来确认输入内容是否有错。但是ajax和jquery都是js的一个库。

## js!=jsp
js（javascript） jsp（java server pages） 
以前在知乎里面看到了一句相当经典的回答，js与jsp的关系就是雷锋和雷峰塔的关系。从这句话可以看出它们俩没有任何联系，而实际上也是这样。jsp其实可以看做一种脚本语言，需要用servlet来编译实现，然而作为一种脚本语言它有相当强大，在其中可以嵌入java代码，jsp中几乎可以使用全部的java类 。其实就是可以把jsp当做html来作为网页显示出来，而且其上还可以嵌套java语言，也可以嵌套其他的语言类似，当然都序言用servlet来编译实现。jsp作为字节码文件执行后可以直接运行，不必每次都要编译，速度快。可能我表述还是有点问题，但是jsp和js大多都应用于web网页的编写上，jsp可以看做html和java的结合体，当然js就可以在jsp上实现一些动作，特效，验证功能，与在html中所实现的效果一样。因为jsp是在服务器端解释执行的，服务器执行转化后的.class程序，客户端接收到的只是服务器发来的html代码，看不到jsp代码。而js可以在客户端通过查看源代码显示出来。

## java,jsp
java是一种编程语言，jsp只是相当于java里面的servlet部分

---
## 后记
记得刚开始开发网站的时候，我的一个学长叫我去看jsp，然后我就用了一个星期看js去了，我还以为js就是jsp，然后就jj了，javascript和jsp也没差多少，所以做了很多的无用功，多走了不该走的弯路，不过后来两个东西都用上了，而且用处都还非常大。重要的事情说三遍，js！=jsp，js！=jsp，js！=jsp。 
js==javascript 
jsp==java server pages 


