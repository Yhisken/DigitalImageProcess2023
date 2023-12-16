# 2023 Fall Digital Image Processing
BLCU-Digital Media Technology Department 21sm2YS，Teacher:ZXW
## Homework—Experiment（Environment：Opencv4.8.0，VS2022 C++ MFC）
## For more information, please refer to branch master
## Content now
### — 1.Open
**Possible potential issues :** <br />
**issues1 :** error C1041: 无法打开程序数据库“xxx\vc140.pdb”；如果要将多个 CL.EXE 写入同一个 .PDB 文件，请使用/FS<br />
**solution :** <https://blog.csdn.net/weixin_38419133/article/details/88597072><br />
**issue2 :** fatal error LNK1201:写入程序数据库“***.pdb”时出错<br />
**solution :** **Delete** x64/Debug/"the DIP-YS.pdb" and then rebuild the solution<br />
**tips :** <br />
—— **Change** the include directory and library directory of opencv to your own<br />
### — 2.Mosaic
**new function :** Menu—subSampling and Mosaic<br />
**Possible potential issues :** <br />
**issue1 :** error C1041: 无法打开程序数据库“xxx\vc140.pdb”；如果要将多个 CL.EXE 写入同一个 .PDB 文件，请使用/FS<br />
**solution :** <https://blog.csdn.net/weixin_38419133/article/details/88597072><br />
**issue2 :** fatal error LNK1201:写入程序数据库“***.pdb”时出错<br />
**solution :** **Delete** x64/Debug/"the DIP-YS.pdb" and then rebuild the solution<br />
**tips :** <br />
—— **Change** the include directory and library directory of opencv to your own<br />
### — 3.Quantize
**new function :** Menu—Quantizerule and Quantize<br />
**Possible potential issues :** <br />
**issue1 :** error C1041: 无法打开程序数据库“xxx\vc140.pdb”；如果要将多个 CL.EXE 写入同一个 .PDB 文件，请使用/FS<br />
**solution :** <https://blog.csdn.net/weixin_38419133/article/details/88597072><br />
**issue2 :** fatal error LNK1201:写入程序数据库“***.pdb”时出错<br />
**solution :** **Delete** x64/Debug/"the DIP-YS.pdb" and then rebuild the solution<br />
**issue3 :** After this project, there may be a problem with all projects. When it comes to entering values in a dialog box, you need to ensure that the size of the image you open is not too large, such as 1920 * 1080. Of course, I don't know the specific legal range, but 1920 * 1080 is absolutely not acceptable.<br />
**tips :** <br />
—— **Change** the include directory and library directory of opencv to your own<br />
### — 4.Color
**new function :** Menu—Added display of several color models(RGB,CMYK,Lab,HSV) and separate display of their respective channels. And it includes the operation of replacing RGB channels with BGR, as well as the operation of adding Hue to the HSV model.<br />
**Possible potential issues :** <br />
**issue1 :** error C1041: 无法打开程序数据库“xxx\vc140.pdb”；如果要将多个 CL.EXE 写入同一个 .PDB 文件，请使用/FS<br />
**solution :** <https://blog.csdn.net/weixin_38419133/article/details/88597072><br />
**issue2 :** fatal error LNK1201:写入程序数据库“***.pdb”时出错<br />
**solution :** **Delete** x64/Debug/"the DIP-YS.pdb" and then rebuild the solution<br />
**tips :** <br />
—— **Change** the include directory and library directory of opencv to your own<br />
———————————————————Update log 2023.12.01—————————————————————<br />
I have rebuilt this repository and now all X64 and .vs directories have been deleted. All you need to do is rebuild<br />
the solution and change the include directory and library directory of opencv to your own.                                 <br />

——————————————————————————————————————————————————<br />

### — 5.Gray and Colorize
**new function :** The menu has added options for **Gray** and **Colorize**. However, considering the need and complexity, there are 5 **Gray** operations here: **Max**,**Min**,**Middle** for RGB,**weighted mean** for HSV,Only **L** for Lab, and **Colorize** only has **JET, HSV, and BONE**. Please add them yourself if needed.<br />
### — 6.Algebra and Logic
**new function :** The menu has added options for **Arithmetic** and **Logical**, which include corresponding function operations, such as **addition, subtraction, and complex variants** in **Arithmetic**. **Logic** include simple **AND, NOR, and other operations**. Please download and view the details yourself.<br />
