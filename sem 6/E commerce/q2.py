class ShoppingCart:
    def __init__(self):
        self.products = [
            {'id': 1, 'name': 'Laptop', 'price': 1254.99},
            {'id': 2, 'name': 'Mouse', 'price': 99.99},
            {'id': 3, 'name': 'Keyboard', 'price': 78.00},
            {'id': 4, 'name': 'Monitor', 'price': 300.00},
            {'id': 5, 'name': 'Headphones', 'price': 124.99}
        ]
        self.cart = []
    
    def show_products(self):
        print("\n" + "="*50)
        print("AVAILABLE PRODUCTS")
        print("="*50)
        for p in self.products:
            print(f"{p['id']}. {p['name']} - ${p['price']:.2f}")
        print("="*50)
    
    def add_to_cart(self, product_id, quantity=1):
        product = next((p for p in self.products if p['id'] == product_id), None)
        if product:
            self.cart.append({
                'product': product,
                'quantity': quantity
            })
            print(f"✓ Added {quantity}x {product['name']} to cart")
        else:
            print("✗ Product not found")
    
    def show_cart(self):
        if not self.cart:
            print("\n Cart is empty")
            return
        
        print("\n" + "="*50)
        print("SHOPPING CART")
        print("="*50)
        total = 0
        for item in self.cart:
            p = item['product']
            qty = item['quantity']
            subtotal = p['price'] * qty
            total += subtotal
            print(f"{p['name']} x{qty} - ${subtotal:.2f}")
        print("-"*50)
        print(f"TOTAL: ${total:.2f}")
        print("="*50)

# Demo usage
shop = ShoppingCart()

shop.show_products()

shop.add_to_cart(1, 1)  # Add 1 Laptop
shop.add_to_cart(2, 2)  # Add 2 Mice
shop.add_to_cart(5, 1)  # Add 1 Headphones

shop.show_cart()