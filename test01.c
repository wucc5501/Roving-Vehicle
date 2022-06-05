struct Vehicle{
    int x;
    int y;
    char orientation; // u:up; d:down; r:right; l:left
};
typedef int bool;  
#define false 0  
#define true  1

typedef struct Vehicle Vehicle;

struct node{
	Vehicle v;
	struct node * link;

}

struct node *queue;

queue=NULL;
queue_end=Null;

void queue_add(Vehicle v){
   struct node *p;
   p=malloc(sizeof(struct node));
   p->v=v;
   p->link=NULL;
   if (queue==NULL){
		queue=p;
		queue_end=p;
	}
	else{
		queue->link=p;
	}
   
}

Vehicle queue_pop(){
	Vehicle v;
	if (queue!=NULL){
		v=queue->v;
		queue=queue->link;
	
		return v;
	}

}

Vehicle start;
Vehicle v;

struct ff{
	int f;  //最少油料
	Vehicle v; //前一筆車位置
	int d; //移動方向 0->fw, 1->bw, 2->ls, 3->rh, 4->cl, 5->cc
} fmap[50][50][4];  //0->u, 1->d, 2->l, 3->r

//找出發位置
queue_add(start);

while (queue!=NULL){
	v=queue_pop()
	if isfw(v){
		//計算新位置
		fw(v)
		//更新油料耗用
		 
		//if 有更新油料耗用的話
		//車子的新位置加入queue
		
	}
	if isbw(v){
		//更新油料耗用
		//if 有更新的話
		//車子的新位置加入queue
		
	}
	if isls(v){
		//更新油料耗用
		//if 有更新的話
		//車子的新位置加入queue
		
	}
	if isrs(v){
		//更新油料耗用
		//if 有更新的話
		//車子的新位置加入queue
		
	}
	if iscc(v){
		//更新油料耗用
		//if 有更新的話
		//車子的新位置加入queue
		
	}
	if iscl(v){
		//更新油料耗用
		//if 有更新的話
		//車子的新位置加入queue
		
	}




}

void isfw(Vehicle v){
	if ((v.orientation=='u') && (map[v.x][v.y-1]!=0) && (map[v.x+1][v.y-1]!=0))
		return 1;
	else if ((v.orientation=='d') && (map[v.x][v.y+1]!=0) && (map[v.x+1][v.y+1]!=0))
		return 1;
		
	else if ((v.orientation=='r') && (map[v.x+1][v.y]!=0) && (map[v.x+1][v.y]!=0))
		return 1;
	else if ((v.orientation=='l') && (map[v.x-1][v.y!=0) && (map[v.x-1][v.y]!=0))
		return 1;
	else
		return 0;
}

Vehicle fw(v){
	Vehicle vv;
	if (v.orientation=='u') {
		vv.x=v.x;
		vv.y=v.y-1;
		if (map[v.x][v.y][0]+1<map[v.x][v.y-1][0])
			map[v.x][v.y-1][0]=map[v.x][v.y][0]+1;
		map[v.x+1][v.y-1][0]=map[v.x+1][v.y][0]+1;
	}	
	else if (v.orientation=='d') {
		vv.x=v.x;
		vv.y=v.y+1;
	}	
	else if (v.orientation=='r'){
		vv.x=v.x+1;
		vv.y=v.y;
	}
	else if (v.orientation=='l'){
		vv.x=v.x-1;
		vv.y=v.y;
	}
	return vv;
}