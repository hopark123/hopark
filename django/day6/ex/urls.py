from . import views
from django.contrib import admin
from django.urls import path

urlpatterns = [
    path('', views.User, name="main"),
    path('register', views.register_request, name="register"),
    path('login', views.login_request, name="login"),
    path('logout', views.logout_request, name="logout"),

]
