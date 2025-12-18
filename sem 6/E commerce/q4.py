class WishListStore:
    def __init__(self):
        self.products = [
            {'id': 1, 'name': 'Laptop', 'price': 1229.99},
            {'id': 2, 'name': 'Smartphone', 'price': 799.99},
            {'id': 3, 'name': 'Headphones', 'price': 89.99},
            {'id': 4, 'name': 'Smartwatch', 'price': 399.99},
            {'id': 5, 'name': 'Camera', 'price': 649.99}
        ]
        self.wishlist = []
    
    def show_products(self):
        print("\n" + "="*50)
        print("AVAILABLE PRODUCTS")
        print("="*50)
        for p in self.products:
            print(f"{p['id']}. {p['name']} - ${p['price']:.2f}")
        print("="*50)
    
    def add_to_wishlist(self, product_id):
        product = next((p for p in self.products if p['id'] == product_id), None)
        if product:
            if product not in self.wishlist:
                self.wishlist.append(product)
                print(f"✓ Added '{product['name']}' to wish list")
            else:
                print(f"✗ '{product['name']}' already in wish list")
        else:
            print("✗ Product not found")
    
    def remove_from_wishlist(self, product_id):
        product = next((p for p in self.wishlist if p['id'] == product_id), None)
        if product:
            self.wishlist.remove(product)
            print(f"✓ Removed '{product['name']}' from wish list")
        else:
            print("✗ Product not in wish list")
    
    def show_wishlist(self):
        if not self.wishlist:
            print("\n Wish list is empty")
            return
        
        print("\n" + "="*50)
        print("MY WISH LIST")
        print("="*50)
        for p in self.wishlist:
            print(f" {p['name']} - ${p['price']:.2f}")
        print("="*50)
        print(f"Total items: {len(self.wishlist)}")

# Demo
store = WishListStore()

store.show_products()

store.add_to_wishlist(1)  # Laptop
store.add_to_wishlist(3)  # Headphones
store.add_to_wishlist(5)  # Camera
store.add_to_wishlist(1)  # Duplicate - won't add

store.show_wishlist()

store.remove_from_wishlist(3)  # Remove Headphones
store.show_wishlist()