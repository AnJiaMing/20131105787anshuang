#include"main.h"
 IplImage * img0=NULL;  
IplImage * img1=NULL;  
CvMat * img2=NULL;  
CvMat *img3=NULL; 
int main( int argc, char** argv)
{
	void capture_frame();
	 int sport( int argc, char** argv ) ;
	CvCapture* capture=0;
	IplImage *frame, *frame_copy=0;
	cvNamedWindow("result",1);
	capture = cvCaptureFromFile("d://Ұ������.avi");
	if (capture){
		for(;;){ 
		if (!cvGrabFrame(capture))
		break;
		frame = cvRetrieveFrame(capture);
		if (!frame)
		break;
		cvShowImage ("result",frame);
		Sleep(30);
		if (cvWaitKey (10) >=0)
		break;
	}
	cvReleaseImage( &frame_copy);
	cvReleaseCapture(&capture);
	}
	cvDestroyWindow("result");

	//CvCapture *avi=cvCreateFileCapture("abc.avi");   ����Ƶ�����ȡ
	//cvSetCaptureProperty(avi,CV_CAP_PROP_POS_FRAMES,1.0); 
	//IplImage *avif=cvQueryFrame(avi); cvReleaseCapture(&avi);
	
	return 0;
}


 void capture_frame(){
  
     char FileName[80];
     memset(FileName,0,sizeof FileName); 
     CvCapture* capture = cvCaptureFromAVI("D:\\Ұ������.avi");
    IplImage* img = 0; 
    int i; 
     i = 0;

     while(cvGrabFrame(capture)){
         img=cvRetrieveFrame(capture);           // retrieve the captured frame
         sprintf(FileName,"D:\\�������\\����\\����2-opencv���ó���\\��Ƶ����ȡ\\��Ƶ����ȡ�ļ�\\%04d.jpg",i);
         cvSaveImage(FileName,img);    
         i++;
     }
 
 
     cvReleaseCapture(&capture);
 }
 
void onTrackerSlid(int pos)  
{  
    cvSub(img0, img1, img2,0);//ͼ�����  
    cvThreshold(img2, img3, pos, 255,0 (CV_THRESH_BINARY));//��ֵ����  
    cvShowImage( "result", img3 );//��ʾ������ͼ��ͼ��  
      
}  
 int sport( int argc, char** argv )  
{    
	
	int thresh = 80;  
//����ͼ��  
	img0=cvLoadImage("d:\\0002.jpg",0);//��������һ����IplImage���壬��Ϊ���Ѿ���ȫ�ֱ���  
	img1=cvLoadImage("d:\\0003.jpg",0);  
  
	img2=cvCreateMat(img0->height,img0->width,CV_8UC1);//����ָ��ĳ�ʼ������cvCreareImage����  
	img3=cvCreateMat(img0->height,img0->width,CV_8UC1);  
	cvSmooth(img0, img0, CV_GAUSSIAN, 3, 0, 0,0);//��˹�˲�ƽ��ͼ��  
 
	cvNamedWindow( "imge0", CV_WINDOW_AUTOSIZE);//��������  
	cvNamedWindow( "imge1", CV_WINDOW_AUTOSIZE);  
	cvNamedWindow( "result", CV_WINDOW_AUTOSIZE);  
	cvShowImage( "imge0", img0 );//��ʾͼ��  
	cvShowImage( "imge1", img1 );  
	cvCreateTrackbar("threshold","result",&thresh,255,onTrackerSlid);  
	onTrackerSlid(thresh);  
	cvWaitKey(0); //�ȴ�����  
	cvDestroyWindow( "Imge0" );//���ٴ���  
	cvDestroyWindow( "Imge1" );  
	cvDestroyWindow( "result" );  
	cvReleaseImage( &img0); //�ͷ�ͼ��  
	cvReleaseImage( &img1);  
	cvReleaseMat( &img2);  
	cvReleaseMat( &img3);  
	return -1;  
}  




