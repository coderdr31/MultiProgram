<head><meta charset="UTF-8"></head>
# 环境
eclipse j2ee
windows-proferences-Server-Runtime Environment: choose tomcat7

##
### mysql workbrench
```
PK Belongs to primary key 作为主键
NN Not Null 非空
UQ Unique index 不能重复
BIN Is binary column 存放二进制数据的列
UN Unsigned data type 无符号数据类型（需要整数形数据）
ZF Fill up values for that column with 0's if it is numeric 填充0位（例如指定3位小数，整数18就会变成18.000）
AI Auto Incremental 自增长
```

### eclipse j2ee
1. 建立JDBC驱动： buildpath导入 & webcontent-webInf-lib加入 mysql-connector-java-5.1.12-bin.jar
2. 格式化代码：ctrl+shift+f
3. jsp注释: ctrl+shift+c

## myproject
deletestuinfo.jsp
modifystuinfo.jsp
inputstuinfo.jsp
displaystuinfo.jsp
exit.jsp
index.jsp 登录界面
islogin.jsp
main.jsp  主界面
main_left.jsp
main_right.jsp
top.jsp
validate.jsp  验证用户

1. 用户登录控制 session
  validate.jsp-islogin.jsp-main.jsp

##################################################################
teacher: tcid tcname tcclass;
