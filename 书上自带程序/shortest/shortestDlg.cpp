// shortestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "shortest.h"
#include "shortestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShortestDlg dialog

CShortestDlg::CShortestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShortestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShortestDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShortestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShortestDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CShortestDlg, CDialog)
	//{{AFX_MSG_MAP(CShortestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShortestDlg message handlers

BOOL CShortestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	CRect rect;
	ShowWindow(SW_SHOWMAXIMIZED); // ��󻯶Ի��򴰿�
    GetClientRect(rect); // �õ��Ի���Ĵ��ڳߴ粢����rect(���Ͻ�Ϊ0,0)
	Dialog.x=rect.right; // ���Ի���Ĵ��ڳߴ縳��ȫ��������Dialog
    Dialog.y=rect.bottom;
	CWnd *pWnd=GetDlgItem(IDOK); // pWndָ���˳�����ť
	pWnd->GetClientRect(rect); // �õ����˳�����ť�ĳߴ粢����rect(���Ͻ�Ϊ0,0)
	pWnd->SetWindowPos(NULL,Dialog.x-rect.right-10,Dialog.y-rect.bottom-10,0,0,SWP_NOSIZE); // ���á��˳�����ť�����½�
	pWnd=GetDlgItem(IDC_STATIC1); // pWndָ��̶��ı���("ȫ����·��ͨʾ��ͼ")
	pWnd->GetClientRect(rect); // �õ��̶��ı���ĳߴ粢����rect(���Ͻ�Ϊ0,0)
	pWnd->SetWindowPos(NULL,(Dialog.x-rect.right)/2,0,0,0,SWP_NOSIZE); // ���ù̶��ı������ϱ߾���
    CreateFromFile(g,"mapvc.txt",0); // ͨ����ǰĿ¼�µ��ļ�mapvc.txt����û�������Ϣ��������g
	int i;
	int Xmin=g.vexs[0].pos.x,Xmax=g.vexs[0].pos.x,Ymin=g.vexs[0].pos.y,Ymax=g.vexs[0].pos.y;
	for(i=1;i<g.vexnum;i++) // ��ö����������Сֵ�����ֵ���ֱ����Xmin��Xmax��Ymin��Ymax
	{
		if(g.vexs[i].pos.x<Xmin)
			Xmin=g.vexs[i].pos.x;
		else if(g.vexs[i].pos.x>Xmax)
			Xmax=g.vexs[i].pos.x;
		if(g.vexs[i].pos.y<Ymin)
			Ymin=g.vexs[i].pos.y;
		else if(g.vexs[i].pos.y>Ymax)
			Ymax=g.vexs[i].pos.y;
	}
	for(i=0;i<g.vexnum;i++) // �����ж���
	{
		g.vexs[i].pos.x=(Dialog.x-4*r)*(g.vexs[i].pos.x-Xmin)/(Xmax-Xmin)+2*r; // �޸Ķ������꣬ʹ����Ӧ��Ļ�ߴ�(�����С���궼��߽�2r)
		g.vexs[i].pos.y=(Dialog.y-4*r)*(g.vexs[i].pos.y-Ymin)/(Ymax-Ymin)+2*r;
		g.arcs[i][i].adj=0; // ShortestPath_FLOYD()Ҫ��Խ�Ԫ��ֵΪ0,��Ϊ������ͬ,�����Ϊ0
	}
	ShortestPath_FLOYD(g,p,d); // ��ͼg��ÿ�Զ��������·�������ڶ�ά����d�У���ά����p�д�ŵ���ÿ�Զ��������·���������Ķ���
	count=0; // ������������������ֵΪ0
	Pen[0].CreatePen(PS_SOLID,1,RGB(0,0,0)); // ��ɫϸʵ�߱�
	Pen[1].CreatePen(PS_DOT,1,RGB(0,0,0)); // ��ɫϸ��(��)�߱�
	pOldPen=NULL;
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShortestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CShortestDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	if (IsIconic())
	{
		//CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		int i,j;
		for(i=0;i<g.vexnum;i++) // �����ж���
			DrawVertexCircle(i,0); // �Ժ�ɫϸʵ�߻����Ϊi�Ķ����Բ
		DrawVertexText(0,3*r,-r/2); // д������³ľ�������
		DrawVertexText(1,0,-r*2); // д������ͺ��ص�����
		DrawVertexText(2,-3*r,-r/2); // д���������������
		for(i=3;i<g.vexnum;i++) // ����
			DrawVertexText(i,0,0); // д�������ƣ�����[0]��[2]�����ƴ���2�����֣����������д���
		for(i=0;i<g.vexnum;i++) // ��(����)
			for(j=0;j<i;j++)
				if(g.arcs[i][j].adj!=INFINITY) // �б�
				{
					DrawLine(i,j,0); // �Ժ�ɫʵϸ���ͻ����ڶ���i�Ͷ���j֮�仭��(����ϸ��)
					DrawLineText(i,j); // �ڶ���i�Ͷ���j֮��ı����Ժͱ�ͬ������Ǳ�ע�ߵ�Ȩֵ
				}
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CShortestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CShortestDlg::CreateFromFile(MGraph &G, char *filename, int IncInfo)
 { // ��������(�ڽӾ���)��ʾ�������ļ�����ͼ����G��IncInfo=0��1����ʾ��(��)�޻��������Ϣ
   int i,j,k;
   VRType w=0; // �����ϵ���ͣ�ͼ
   VertexType v1,v2; // ��������
   FILE *f; // �ļ�ָ������
   f=fopen(filename,"r"); // �������ļ�������f��ʾ
   fscanf(f,"%d",&G.kind); // ���ļ�����G������
   if(G.kind%2) // ��
     w=INFINITY;
   fscanf(f,"%d",&G.vexnum); // ���ļ�����G�Ķ�����
   for(i=0;i<G.vexnum;++i)
     InputFromFile(f,G.vexs[i]); // ���ļ����붥����Ϣ
   fscanf(f,"%d",&G.arcnum); // ���ļ�����G�Ļ�(��)��
   for(i=0;i<G.vexnum;++i) // ��ʼ����ά�ڽӾ���
     for(j=0;j<G.vexnum;++j)
     {
       G.arcs[i][j].adj=w; // ������
       G.arcs[i][j].info=NULL; // û�������Ϣ
     }
   if(!(G.kind%2)) // ͼ
     w=1;
   for(k=0;k<G.arcnum;++k) // �������л�
   {
     fscanf(f,"%s%s",v1.name,v2.name); // ���뻡β����ͷ������
     if(G.kind%2) // ��
       fscanf(f,"%d",&w); // ������Ȩֵ
     i=LocateVex(G,v1); // ��β�����
     j=LocateVex(G,v2); // ��ͷ�����
     G.arcs[i][j].adj=w; // Ȩֵ
     if(IncInfo) // �������Ϣ
       InputArcFromFile(f,G.arcs[i][j].info);
       // ���ļ���̬���ɴ洢�ռ䣬���뻡�������Ϣ
     if(G.kind>1) // ����
       G.arcs[j][i]=G.arcs[i][j]; // ����������Ԫ����Ϣ��ͬ
   }
   fclose(f); // �ر������ļ�
 }

void CShortestDlg::InputFromFile(FILE *f, VertexType &ver) // ��֮���׵Ĵ��ļ����붥����Ϣ�ĺ���
{
   fscanf(f,"%s%d%d",ver.name,&ver.pos.x,&ver.pos.y);
}

int CShortestDlg::LocateVex(MGraph G, VertexType u)
 { // ��ʼ������ͼG���ڣ�u��G�ж�������ͬ����(����������ͬ)
   // �����������G�д��ڶ���u���򷵻ظö�����ͼ��λ��(���)�����򷵻�-1
   int i;
   for(i=0;i<G.vexnum;++i) // �������ж������β���
     if(strcmp(u.name,G.vexs[i].name)==0) // �����������u�Ķ���������ͬ
       return i; // ���ض������
   return -1; // ͼG�в������붥��u����ͬ���ƵĶ���
 }

void CShortestDlg::InputArcFromFile(FILE *f, InfoType *&arc) // ���ļ����뻡(��)�������Ϣ�ĺ���(��)
{
}

void CShortestDlg::ShortestPath_FLOYD(MGraph G, PathMatrix P, DistancMatrix D)
 { // ��Floyd�㷨��������G�и��Զ���v��w֮������·��P[v][w][]�����Ȩ����D[v][w]��
   // ��P[v][w][u]ΪTRUE����u�Ǵ�v��w��ǰ������·���ϵĶ��㡣�㷨7.16
   int u,v,w,i;
   for(v=0;v<G.vexnum;v++) // ���Խ��֮���ʼ��֪·��������
     for(w=0;w<G.vexnum;w++)
     {
       D[v][w]=G.arcs[v][w].adj; // ����v������w��ֱ�Ӿ���
       for(u=0;u<G.vexnum;u++)
         P[v][w][u]=FALSE; // ·�������ֵ
       if(D[v][w]<INFINITY) // ��v��w��ֱ��·��
         P[v][w][v]=P[v][w][w]=TRUE; // ��v��w��·������v��w����
     }
   for(u=0;u<G.vexnum;u++)
     for(v=0;v<G.vexnum;v++)
       for(w=0;w<G.vexnum;w++)
         if(D[v][u]<INFINITY&&D[u][w]<INFINITY&&D[v][u]+D[u][w]<D[v][w])
         { // ��v��u��w��һ��·������
           D[v][w]=D[v][u]+D[u][w]; // ������̾���
           for(i=0;i<G.vexnum;i++)
             P[v][w][i]=P[v][u][i]||P[u][w][i];
             // ��v��w��·��������v��u�ʹ�u��w������·��
         }
 }

void CShortestDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CString strMessage,ss;
	int i,k;
	for(i=0;i<g.vexnum;i++) // ����������������i
	{
		X=double(point.x-g.vexs[i].pos.x);
		Y=double(point.y-g.vexs[i].pos.y);
		if(int(hypot(X,Y))<=r) // hypot()��б��
		{
			count++;
			break;
		}
	}
	if(i<g.vexnum) // ����������Ϊi�Ķ���
	{
		if(count%2) // ����������������(������)
		{
			if(count>1) // ���ǵ�һ������̾��룬Ҫ�úڱ��ػ�
			{
				DrawVertexCircle(number[0],0); // �úڱ��ػ����
				DrawVertexCircle(number[1],0); // �úڱ��ػ��յ�
				k=1;
				while(pa[k]!=-1) // pa[k]�����ξ����Ķ������
				{
					DrawLine(pa[k-1],pa[k],0); // �Ժ�ɫʵϸ���ͻ����ڶ���pa[k-1]�Ͷ���pa[k]֮�仭��(����ϸ��)
					DrawVertexCircle(pa[k],0); // �úڱ��ػ����ξ����Ķ���
					k++;
				};
			}
			DrawVertexCircle(i,1); // �����߱��ػ��������֮����(���)
			number[0]=i; // �ö���Ϊ���
			SetWindowLong(GetSafeHwnd(),GWL_STYLE,GetWindowLong(GetSafeHwnd(),GWL_STYLE)& (~WS_MINIMIZEBOX)); // ʹ�Ի�����С����ť������
		}
		else // ����������ż���Σ�����յ㣩
		{
			number[1]=i; // �ö���Ϊ�յ�
			if(d[number[0]][number[1]]<INFINITY) // ��ͨ·
			{
				path1(g,p,number[0],number[1],pa); // �����·�����������е��յ������;�������ĳ��У��䶥����Ŵ�������pa
				strMessage.Format("%s��%s����̾���Ϊ%d\n;��: %s ",g.vexs[number[0]].name,g.vexs[number[1]].name,d[number[0]][number[1]],g.vexs[pa[0]].name);
				int k=1;
				while(pa[k]!=-1)
				{
					DrawLine(pa[k-1],pa[k],1); // �Ժ�ɫ���߻����ڶ���pa[k-1]�Ͷ���pa[k]֮�仭��(����ϸ��)
					DrawVertexCircle(pa[k],1); // �����߱��ػ�����֮����
					ss.Format("%s ",g.vexs[pa[k++]].name);
					strMessage+=ss;
				}
			}
			else
			{
				DrawVertexCircle(i,1); // �����߱��ػ��������֮����(�յ�)
				strMessage.Format("%s��%sû��·����ͨ\n",g.vexs[number[0]].name,g.vexs[number[1]].name);
				pa[1]=-1; // û��·����ͨ������£������úڱ��ػ�ֱ�ߵı�־
			}
			MessageBox(strMessage,"���·��");
			SetWindowLong(GetSafeHwnd(),GWL_STYLE,GetWindowLong(GetSafeHwnd(),GWL_STYLE)^ (WS_MINIMIZEBOX)); // ʹ�Ի�����С����ť���¿���
		}
	}	
	CDialog::OnLButtonDown(nFlags, point);
}

void CShortestDlg::path1(MGraph G, PathMatrix P, int i, int j, int pa[])
{ // �������Ϊi�������е����Ϊj���յ�������·����;�������ĳ��У���������pa[]��
	int k,n=0,m=i; // ��������Ÿ���m
	for(k=0;k<G.vexnum;k++)
		pa[k]=-1; // pa�ĳ�ֵ
	while(m!=j) // û���յ����
	{
		G.arcs[m][m].adj=INFINITY; // �Խ�Ԫ�ظ�ֵ�����
		for(k=0;k<G.vexnum;k++)
			if(G.arcs[m][k].adj<INFINITY&&P[m][j][k]) // m��k��ֱ��ͨ·����k��m��j�����·����
			{
				pa[n++]=m;
				G.arcs[m][k].adj=G.arcs[k][m].adj=INFINITY; // ��ֱ��ͨ·��Ϊ��ͨ
				m=k; // �����ĳ�����Ÿ���m����������
				break;
			}
	}
	pa[n]=j; // �յ����
}

void CShortestDlg::DrawVertexCircle(int n, int i)
{ // �Ժ�ɫPen[i]ϸ���ͻ����Ϊn�Ķ����Բ
	CDC* pDC=GetDC(); // �õ��豸����(�Ա㻭ͼ)
	pDC->SelectStockObject(NULL_BRUSH); // ͼ��͸��(�����)
	pOldPen=pDC->SelectObject(&Pen[i]); // ѡ���ɫPen[i]�͵�ϸ�߻���
	pDC->Ellipse(g.vexs[n].pos.x-r,g.vexs[n].pos.y-r,g.vexs[n].pos.x+r,g.vexs[n].pos.y+r); // �õ�ǰɫ�Ļ��ʻ����Ϊn��Բ
	pDC->SelectObject(pOldPen); // �ָ�ԭ�еĻ���
	ReleaseDC(pDC); //  ��pDC=GetDC()��Ӧ
}

void CShortestDlg::DrawVertexText(int n,int x,int y)
{ // �ھඥ��n������(x,y)��д��������
	CDC* pDC=GetDC(); // �õ��豸����(�Ա�д�ı�)
	pDC->SetBkMode(TRANSPARENT); // �����ı�����Ϊ͸����
	pDC->SetTextAlign(TA_CENTER); // �����ı����뷽ʽ��ָ�������м�
	CFont *pOldFont=NULL,fnBig;
	fnBig.CreatePointFont(90,"����",NULL); // �����ı����ֺź�����
	pOldFont=pDC->SelectObject(&fnBig);
	pDC->TextOut(g.vexs[n].pos.x+x,g.vexs[n].pos.y-r/2+y,g.vexs[n].name);
	pDC->SelectObject(pOldFont); // �ָ�ԭ�е������񣬷ǳ���Ҫ
	ReleaseDC(pDC); //  ��pDC=GetDC()��Ӧ
}

void CShortestDlg::DrawLineText(int m, int n)
{ // �ڶ���m�Ͷ���n֮��ı����Ժͱ�ͬ������Ǳ�ע�ߵ�Ȩֵ
	int q;
	CDC* pDC=GetDC(); // �õ��豸����(�Ա�д�ı�)
	pDC->SetBkMode(TRANSPARENT); // �����ı�����Ϊ͸����
	pDC->SetTextAlign(TA_CENTER); // �����ı����뷽ʽ��ָ�������м�
	X=g.vexs[n].pos.x-g.vexs[m].pos.x;
	Y=g.vexs[n].pos.y-g.vexs[m].pos.y;
	R=hypot(X,Y); // �ߵĳ��ȣ��ɶ�����������
	q=int(atan2(-Y,X)*1800/3.14159216); // �ߵ���ǣ���λ��0.1��
	if(q>1350) // ʹ�ߵ������-45�㡫135��֮��
		q-=1800;
	else if(q<-450)
		q+=1800;
	CFont fnBig;
	fnBig.CreateFont(r,0,q,0,0,FALSE,FALSE,FALSE,ANSI_CHARSET,OUT_DEFAULT_PRECIS, // ������б��������
	CLIP_DEFAULT_PRECIS,PROOF_QUALITY,DEFAULT_PITCH+FF_DONTCARE,"Times New Roman");  
	CFont *pOldFont=pDC->SelectObject(&fnBig); // ѡ����б�����壬����ԭ�е����������pOldFont���ǳ���Ҫ
	CString str;
	str.Format("%d",g.arcs[m][n].adj); // �ߵ�Ȩֵ������str
	pDC->TextOut(g.vexs[n].pos.x-int(X/2),g.vexs[n].pos.y-int(Y/2)+2,str); // ����б�������ڱߵĸ���дȨֵ
	pDC->SelectObject(pOldFont); // �ָ�ԭ�е������񣬷ǳ���Ҫ
	ReleaseDC(pDC); //  ��pDC=GetDC()��Ӧ
}

void CShortestDlg::DrawLine(int m, int n, int i)
{ // �Ժ�ɫPen[i]ϸ���ͻ����ڶ���m�Ͷ���n֮�仭��(����ϸ��)
	int x,y;
	CDC* pDC=GetDC(); // �õ��豸����(�Ա㻭ͼ)
	pDC->SelectStockObject(NULL_BRUSH); // ͼ��͸��(�����)
	pOldPen=pDC->SelectObject(&Pen[i]); // ѡ���ɫPen[i]�͵�ϸ�߻���
	X=g.vexs[n].pos.x-g.vexs[m].pos.x;
	Y=g.vexs[n].pos.y-g.vexs[m].pos.y;
	R=hypot(X,Y); // �ߵĳ��ȣ��ɶ�����������
	x=int(r*X/R); // ��������ǣ�Բ�ĵ�Բ��ˮƽ����ֱ�ľ���
	y=int(r*Y/R);
	pDC->MoveTo(g.vexs[m].pos.x+x,g.vexs[m].pos.y+y); // ���������Բ���𻭱�
	pDC->LineTo(g.vexs[n].pos.x-x,g.vexs[n].pos.y-y);
	pDC->SelectObject(pOldPen); // �ָ�ԭ�еĻ���
	ReleaseDC(pDC); //  ��pDC=GetDC()��Ӧ
}
