class ProductManager:
    def __init__(self):
        self.categories = {}
    
    def add_category(self, category_name):
        if category_name not in self.categories:
            self.categories[category_name] = []
            print(f"✓ Category '{category_name}' created")
        else:
            print(f"✗ Category '{category_name}' already exists")
    
    def add_product(self, category, product_name, price):
        if category in self.categories:
            self.categories[category].append({
                'name': product_name,
                'price': price
            })
            print(f"✓ Added '{product_name}' to {category}")
        else:
            print(f"✗ Category '{category}' not found")
    
    def display_all(self):
        if not self.categories:
            print("No categories available")
            return
        
        print("\n" + "="*50)
        print("PRODUCT CATALOG")
        print("="*50)
        
        for category, products in self.categories.items():
            print(f"\n {category.upper()}")
            print("-" * 50)
            if products:
                for p in products:
                    print(f"  • {p['name']} - ${p['price']:.2f}")
            else:
                print("  (No products)")
        print("="*50)

# Demo usage
store = ProductManager()

# Create categories
store.add_category("Electronics")
store.add_category("Clothing")
store.add_category("Books")

# Add products
store.add_product("Electronics", "Laptop", 1254.99)
store.add_product("Electronics", "Headphones", 124.99)
store.add_product("Electronics", "Mouse", 99.99)

store.add_product("Clothing", "T-Shirt", 24.99)
store.add_product("Clothing", "Jeans", 49.99)

store.add_product("Books", "Python Guide", 15.99)
store.add_product("Books", "Design Patterns", 29.99)

# Display everything
store.display_all()