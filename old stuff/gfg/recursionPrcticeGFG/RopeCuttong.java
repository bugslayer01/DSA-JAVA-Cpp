public class RopeCuttong {
    static int peices(int a[],int size, int cut){
        if(size>a[0]&&size<a[1]&&size<a[2]){
            size = size - a[0];cut++;
            peices(a, size, cut);
        }
        else if(size>a[1]&&size<a[2]&&size<a[0]){
            size = size - a[1];cut++;
            peices(a, size, cut);
        }
        else if(size>a[2]&&size<a[0]&&size<a[1]){
            size = size - a[2];cut++;
            peices(a, size, cut);
        }
        else if (size==0)
        {return cut;}
        else{
            return -1;
        }

       
    }
}
