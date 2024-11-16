class Rectangle{
	private:
		double length;
		double width;
		double area;
		
	public:
		void setLength(double l){
			length = l;
		}
		
		void setWidth(double w){
			width = w;
		}
		
		double getLength(){
			return length;
		}
		
		double getWidth(){
			return width;
		}
		
		double getArea(){
			area = length * width;
			return area;
		}
	 
	
	
	
};

